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


extern "C" bool __atomic_test_and_set(volatile void* ptr, int memorder) {
  (void)memorder; // unused
  bool old = *(volatile bool*)ptr;
  *(volatile bool*)ptr = true;
  return old;
}

extern "C" void __atomic_clear(volatile void* ptr, int memorder) {
  (void)memorder;
  *(volatile bool*)ptr = false;
}



// -------------------- Config --------------------
#define I2S_DATA_PIN  9
#define I2S_BCLK_PIN  10
#define I2S_BUFFERS   4
#define I2S_WORDS     64
#define SAMPLE_RATE   44100
#define HV_NOTEIN_HASH 0x67E37CA3

// -------------------- Heavy & I2S --------------------
Heavy_oscilator pd_prog(SAMPLE_RATE);
I2S i2s_output(OUTPUT);

float samples[2 * I2S_WORDS];
int16_t left_buffer[I2S_WORDS];
int16_t right_buffer[I2S_WORDS];

// -------------------- USB MIDI --------------------
Adafruit_USBD_MIDI usb_midi;

// -------------------- Heavy note helpers --------------------
void sendHeavyNoteOn(Heavy_oscilator* pd, int note, int velocity) {
  hv_sendMessageToReceiverFF(pd, HV_NOTEIN_HASH, 0.0, note, velocity);
}

void sendHeavyNoteOff(Heavy_oscilator* pd, int note) {
  hv_sendMessageToReceiverFF(pd, HV_NOTEIN_HASH, 0.0, note, 0.0);
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
    if (step == 2) { 
      data2 = b; 
      step = 0; 
      if (status == 0x90 && data2 > 0) sendHeavyNoteOn(&pd_prog, data1, data2);
      else if (status == 0x80 || (status == 0x90 && data2 == 0)) sendHeavyNoteOff(&pd_prog, data1);
    }
  }
}

// -------------------- Setup --------------------
void setup() {
  // I2S config
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

  // Process Heavy
  pd_prog.processInlineInterleaved(samples, samples, I2S_WORDS);

  // Convert to int16 and write to I2S
  for (uint32_t i = 0; i < I2S_WORDS; i++) {
    left_buffer[i]  = int16_t(samples[2*i] * 32767.0f);
    right_buffer[i] = int16_t(samples[2*i+1] * 32767.0f);
    i2s_output.write16(right_buffer[i], left_buffer[i]);
  }
}

