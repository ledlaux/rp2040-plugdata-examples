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

#define I2S_DATA_PIN  9
#define I2S_BCLK_PIN  10
#define SAMPLE_RATE   44100
#define AUDIO_BLOCK   128

float audioBlock[2*AUDIO_BLOCK];
int16_t left[AUDIO_BLOCK];
int16_t right[AUDIO_BLOCK];

#define HV_NOTEIN_HASH  0x67E37CA3
#define HV_NOTEOUT_HASH 0xD1D4AC2

I2S i2s_output(OUTPUT);
Heavy_oscilator pd_prog(SAMPLE_RATE);
Adafruit_USBD_MIDI usb_midi;

// --- Potentiometer volume ---
#define VOL_PIN A0
float volume = 1.0f;
int lastPot = -1;

void setup() {
  Serial.begin(115200);

  usb_midi.begin();
  while (!TinyUSBDevice.mounted()) delay(10); // Wait for USB enumeration

  i2s_output.setFrequency(SAMPLE_RATE);
  i2s_output.setDATA(I2S_DATA_PIN);
  i2s_output.setBCLK(I2S_BCLK_PIN);
  i2s_output.setBitsPerSample(16);
  i2s_output.setBuffers(4, AUDIO_BLOCK);
  i2s_output.begin();
  pd_prog.setSendHook(heavyNoteOutHook);

  Serial.println("USB MIDI ready!");
}


// --- Forward Heavy noteout → USB MIDI ---

void heavyNoteOutHook(HeavyContextInterface *c, const char *receiverName, hv_uint32_t receiverHash, const HvMessage *m) {
  if (receiverHash == HV_NOTEOUT_HASH) {
    int note     = (int)msg_getFloat(m, 0);
    int velocity = (int)msg_getFloat(m, 1);

    uint8_t channel = 0; // MIDI channel 1
    uint8_t midiMsg[3];

    if (velocity > 0) {
      midiMsg[0] = 0x90 | channel;
      midiMsg[1] = note;
      midiMsg[2] = velocity;
    } else {
      midiMsg[0] = 0x80 | channel;
      midiMsg[1] = note;
      midiMsg[2] = 0;
    }

    if (tud_mounted()) usb_midi.write(midiMsg, 3);
  }
}

// --- Handle incoming USB MIDI → Heavy ---
void handleUsbMidi() {
  static uint8_t status=0, data1=0, data2=0, step=0;

  while (usb_midi.available()) {
    int byte = usb_midi.read();
    if(byte < 0) break;

    if (byte & 0x80) { status = byte & 0xF0; step=1; continue; }
    if (step==1) { data1=byte; step=2; continue; }
    if (step==2) {
      data2=byte; step=0;
      switch(status){
        case 0x90:
          if(data2>0)
            hv_sendMessageToReceiverFF(&pd_prog, HV_NOTEIN_HASH, 0.0, data1, data2);
          else
            hv_sendMessageToReceiverFF(&pd_prog, HV_NOTEIN_HASH, 0.0, data1, 0.0);
          break;
        case 0x80:
          hv_sendMessageToReceiverFF(&pd_prog, HV_NOTEIN_HASH, 0.0, data1, 0.0);
          break;
      }
    }
  }
}


void loop() {
  handleUsbMidi();

  int potVal = analogRead(VOL_PIN);
  if(potVal != lastPot){
    lastPot = potVal;
    volume = potVal / 4095.0f;
  }
  pd_prog.processInlineInterleaved(audioBlock, audioBlock, AUDIO_BLOCK);

  // Convert audio to int16
  for(int i=0; i<AUDIO_BLOCK; i++){
    left[i]  = int16_t(audioBlock[2*i]   * 32767.0f * volume);
    right[i] = int16_t(audioBlock[2*i+1] * 32767.0f * volume);
  }

  // Write I2S block
  for(int i=0; i<AUDIO_BLOCK; i++){
    i2s_output.write16(left[i], right[i]);
  }
}
