#include <I2S.h>
#include <Adafruit_TinyUSB.h>
#include "Heavy_oscilator.hpp"

// --- Atomic stubs for RP2040 ---
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

// -------------------- Config --------------------
#define I2S_DATA_PIN   9
#define I2S_BCLK_PIN   10
#define I2S_BUFFERS    4
#define I2S_WORDS      64
#define SAMPLE_RATE    44100
#define FREQ_POT_PIN   A0

// -------------------- Heavy & I2S --------------------
Heavy_oscilator pd_prog(SAMPLE_RATE);
I2S i2s_output(OUTPUT);

float samples[2 * I2S_WORDS];
int16_t left_buffer[I2S_WORDS];
int16_t right_buffer[I2S_WORDS];

// -------------------- USB MIDI --------------------
Adafruit_USBD_MIDI usb_midi;

// -------------------- Heavy note helpers --------------------
#define HV_NOTEIN_HASH 0x67E37CA3  // numeric hash for notein

void sendHeavyNoteOn(Heavy_oscilator* pd, int note, int velocity) {
  hv_sendMessageToReceiverFF(pd, HV_NOTEIN_HASH, 0.0f, note, velocity);
}

void sendHeavyNoteOff(Heavy_oscilator* pd, int note) {
  hv_sendMessageToReceiverFF(pd, HV_NOTEIN_HASH, 0.0f, note, 0);
}

// -------------------- USB MIDI handler --------------------
void handleUsbMidi() {
  static uint8_t status = 0;
  static uint8_t data1 = 0;
  static uint8_t data2 = 0;
  static uint8_t step = 0;

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
      if (status == 0x90 && data2 > 0)
        sendHeavyNoteOn(&pd_prog, data1, data2);
      else if (status == 0x80 || (status == 0x90 && data2 == 0))
        sendHeavyNoteOff(&pd_prog, data1);
    }
  }
}

// -------------------- Setup --------------------
void setup() {
  // --- I2S output setup ---
  i2s_output.setFrequency(SAMPLE_RATE);         // e.g., 44100 Hz
  i2s_output.setDATA(I2S_DATA_PIN);            // GPIO pin for DATA
  i2s_output.setBCLK(I2S_BCLK_PIN);            // GPIO pin for bit clock
  i2s_output.setBitsPerSample(16);             // 16-bit audio
  i2s_output.setBuffers(I2S_BUFFERS, I2S_WORDS); // buffer count & size
  i2s_output.begin();                           // start I2S

  // --- USB MIDI setup ---
  usb_midi.begin();                             // initialize USB MIDI

  // --- Potentiometer setup ---
  pinMode(FREQ_POT_PIN, INPUT);                // frequency control
                // ensure 12-bit ADC
}

// -------------------- Main loop --------------------
void loop() {
  handleUsbMidi();

int potVal = analogRead(FREQ_POT_PIN);       // 0–4095 
int midiVal = 1 + (potVal * 126) / 1000;     // map to 1–127
hv_sendMessageToReceiverV(&pd_prog, 0x345FC008, 0.0, "f", (float)midiVal);

  // Process audio
  pd_prog.processInlineInterleaved(samples, samples, I2S_WORDS);

  for (uint32_t i = 0; i < I2S_WORDS; i++) {
    left_buffer[i]  = int16_t(samples[2*i]   * 32767.0f);
    right_buffer[i] = int16_t(samples[2*i+1] * 32767.0f);
    i2s_output.write16(right_buffer[i], left_buffer[i]);
  }
}
