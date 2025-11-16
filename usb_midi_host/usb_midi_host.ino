// USB midi host example is using rppicomidi/usb_midi_host library


#include <I2S.h>
#include "Heavy_oscilator.hpp"
#include <Adafruit_TinyUSB.h>
#include "usb_midi_host.h"

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

// --- I2S config ---
#define I2S_DATA_PIN  9
#define I2S_BCLK_PIN  10
#define SAMPLE_RATE   44100
#define AUDIO_BLOCK   128

float audioBlock[2*AUDIO_BLOCK];
int16_t left[AUDIO_BLOCK];
int16_t right[AUDIO_BLOCK];

// --- Heavy receiver hashes ---
#define HV_NOTEIN_HASH 0x67E37CA3
#define HV_CCTLIN_HASH 0x41BE0F9C   // CC input hash

// --- Objects ---
I2S i2s_output(OUTPUT);
Heavy_oscilator pd_prog(SAMPLE_RATE);

// --- USB Host MIDI ---
#define MIDI_UART Serial1
Adafruit_USBH_Host USBHost;
uint8_t midi_dev_addr = 0;

// --- Volume controlled via CC#7 ---
float volume = 1.0f;

// --- Heavy helpers ---
void sendHeavyNoteOn(int note, int velocity) { 
  hv_sendMessageToReceiverFF(&pd_prog, HV_NOTEIN_HASH, 0.0, note, velocity);
}
void sendHeavyNoteOff(int note) { 
  hv_sendMessageToReceiverFF(&pd_prog, HV_NOTEIN_HASH, 0.0, note, 0.0);
}
void sendHeavyCC(int cc, int value) {
  hv_sendMessageToReceiverFF(&pd_prog, HV_CCTLIN_HASH, 0.0, cc, value);
}

// --- USB MIDI Host handler ---
void handleUsbMidi() {
  if (midi_dev_addr == 0) return;

  uint8_t cable;
  uint8_t buffer[4];

  while (true) {
    int n = tuh_midi_stream_read(midi_dev_addr, &cable, buffer, sizeof(buffer));
    if (n <= 0) break;

    for (int i = 0; i < n; i++) {
      uint8_t byte = buffer[i];

      static uint8_t status = 0, data1 = 0, data2 = 0, step = 0;

      if (byte & 0x80) { status = byte & 0xF0; step = 1; continue; }

      if (step == 1) { data1 = byte; step = 2; continue; }
      if (step == 2) {
        data2 = byte; step = 0;

        switch (status) {
          case 0x90: if (data2 > 0) sendHeavyNoteOn(data1, data2); else sendHeavyNoteOff(data1); break;
          case 0x80: sendHeavyNoteOff(data1); break;
          case 0xB0: // CC
            sendHeavyCC(data1, data2);
            if (data1 == 7) volume = data2 / 127.0f; // CC#7 = volume
            break;
        }
      }
    }
  }
}

// --- Setup ---
void setup() {
  MIDI_UART.begin(31250);  // MIDI baud
  USBHost.begin(0);

  // I2S
  i2s_output.setFrequency(SAMPLE_RATE);
  i2s_output.setDATA(I2S_DATA_PIN);
  i2s_output.setBCLK(I2S_BCLK_PIN);
  i2s_output.setBitsPerSample(16);
  i2s_output.setBuffers(4, AUDIO_BLOCK);
  i2s_output.begin();
}

// --- Main loop ---
void loop() {
  USBHost.task();
  handleUsbMidi();

  // Generate audio
  pd_prog.processInlineInterleaved(audioBlock, audioBlock, AUDIO_BLOCK);

  // Apply volume and convert to int16
  for(int i=0;i<AUDIO_BLOCK;i++){
    left[i]  = int16_t(audioBlock[2*i] * 32767.0f * volume);
    right[i] = int16_t(audioBlock[2*i+1] * 32767.0f * volume);
  }

  // Write block
  for(int i = 0; i < AUDIO_BLOCK; i++){
    i2s_output.write16(left[i], right[i]);
  }
}

// --- TinyUSB callbacks ---
void tuh_midi_mount_cb(uint8_t dev_addr, uint8_t, uint8_t, uint8_t, uint16_t) {
  midi_dev_addr = dev_addr;
}
void tuh_midi_umount_cb(uint8_t dev_addr, uint8_t) {
  if (dev_addr == midi_dev_addr) midi_dev_addr = 0;
}
void tuh_midi_rx_cb(uint8_t, uint32_t) {}
void tuh_midi_tx_cb(uint8_t) {}
