/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */


#include <I2S.h>
#include <Adafruit_TinyUSB.h>
#include "Heavy_oscilator.hpp"

// --- Atomic stubs for RP2040 only ---
#if defined(ARDUINO_ARCH_RP2040)
extern "C" bool __atomic_test_and_set(volatile void* ptr, int memorder) {
    (void)memorder;
    bool old = *(volatile bool*)ptr;
    *(volatile bool*)ptr = true;
    return old;
}
extern "C" void __atomic_clear(volatile void* ptr, int memorder) {
    (void)memorder;
    *(volatile bool*)ptr = false;
}
#endif

// -------------------- Config --------------------
#define I2S_DATA_PIN  9
#define I2S_BCLK_PIN  10
#define I2S_BUFFERS   4
#define I2S_WORDS     64
#define SAMPLE_RATE   22050 // Higher sample rate is not stable
#define MAX_VOICES    4

// -------------------- Heavy & I2S --------------------
Heavy_oscilator pd_prog(SAMPLE_RATE);
I2S i2s_output(OUTPUT);

float samples[2 * I2S_WORDS];   // interleaved stereo
int16_t left_buffer[I2S_WORDS];
int16_t right_buffer[I2S_WORDS];

// -------------------- USB MIDI --------------------
Adafruit_USBD_MIDI usb_midi;

// -------------------- Voice allocation --------------------
struct Voice {
  uint8_t note = 0;
  bool active = false;
  hv_uint32_t hash = 0;
};

// Match your [r NOTE#] objects in Heavy
constexpr hv_uint32_t VOICE_HASHES[MAX_VOICES] = {
  0x3E185FE5,  // NOTE1
  0x3C682D20,  // NOTE2
  0xC430EA70,  // NOTE3
  0xD3ABA527   // NOTE4
};

Voice voices[MAX_VOICES];

// -------------------- Voice functions --------------------
int allocateVoice(uint8_t note) {
  for (int i = 0; i < MAX_VOICES; i++) {
    if (!voices[i].active) {
      voices[i].note = note;
      voices[i].active = true;
      voices[i].hash = VOICE_HASHES[i];
      return i;
    }
  }
  // No free voices, do nothing
  return -1;
}

int findVoiceByNote(uint8_t note) {
  for (int i = 0; i < MAX_VOICES; i++) {
    if (voices[i].active && voices[i].note == note) return i;
  }
  return -1;
}

void sendVoiceNoteOn(int voiceIndex, uint8_t note, uint8_t velocity) {
  hv_sendMessageToReceiverV(&pd_prog, voices[voiceIndex].hash, 0.0f, "fff",
                            (float)note, (float)velocity, 0.0f);
}

void sendVoiceNoteOff(int voiceIndex, uint8_t note) {
  hv_sendMessageToReceiverV(&pd_prog, voices[voiceIndex].hash, 0.0f, "fff",
                            (float)note, 0.0f, 0.0f);
  voices[voiceIndex].active = false;
}

// -------------------- USB MIDI handler --------------------
void handleUsbMidi() {
  static uint8_t status = 0;
  static uint8_t data1  = 0;
  static uint8_t data2  = 0;
  static uint8_t step   = 0;

  int byteRead;
  while ((byteRead = usb_midi.read()) >= 0) {
    uint8_t b = byteRead & 0xFF;

    if (b & 0x80) { // status byte
      status = b & 0xF0;
      step = 1;
      continue;
    }

    if (step == 1) { data1 = b; step = 2; continue; }
    if (step == 2) { data2 = b; step = 0;

      if (status == 0x90 && data2 > 0) {           // Note On
        int voice = allocateVoice(data1);
        if (voice >= 0) sendVoiceNoteOn(voice, data1, data2);
      } else if (status == 0x80 || (status == 0x90 && data2 == 0)) { // Note Off
        int voice = findVoiceByNote(data1);
        if (voice >= 0) sendVoiceNoteOff(voice, data1);
      }
    }
  }
}

// -------------------- Setup --------------------
void setup() {
  // I2S
  i2s_output.setFrequency(SAMPLE_RATE);
  i2s_output.setDATA(I2S_DATA_PIN);
  i2s_output.setBCLK(I2S_BCLK_PIN);
  i2s_output.setBitsPerSample(16);
  i2s_output.setBuffers(I2S_BUFFERS, I2S_WORDS);
  i2s_output.begin();

  // USB MIDI
  usb_midi.begin();
}

// -------------------- Main loop --------------------
void loop() {
  handleUsbMidi();

  // Process entire Heavy patch
  pd_prog.processInlineInterleaved(samples, samples, I2S_WORDS);

  // Convert to int16 and write interleaved to I2S
  for (uint32_t i = 0; i < I2S_WORDS; i++) {
    left_buffer[i]  = int16_t(samples[2*i] * 32767.0f);
    right_buffer[i] = int16_t(samples[2*i+1] * 32767.0f);
    i2s_output.write16(right_buffer[i], left_buffer[i]);
  }
}
