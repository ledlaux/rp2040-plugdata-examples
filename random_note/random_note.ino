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

// // --- Hardware random seed ---
// class Trand {

//   public: Trand();

// };

// */Trand::Trand() {
  
//   uint32_t random = 0;
//   uint32_t random_bit;
//   volatile uint32_t *rnd_reg = (uint32_t *)(ROSC_BASE + ROSC_RANDOMBIT_OFFSET);

//   for (int k = 0; k < 32; k++) {
//     while (1) {
//       random_bit = (*rnd_reg) & 1;
//       if (random_bit != ((*rnd_reg) & 1)) break;
//     }

//     random = (random << 1) | random_bit;
//   }
  
//   srand(random);

// }

//   Trand Trand;


// --- I2S config ---
#define I2S_DATA_PIN  9
#define I2S_BCLK_PIN  10
#define SAMPLE_RATE   44100
#define AUDIO_BLOCK   128
float volume = 0.5f;

float audioBlock[2*AUDIO_BLOCK];
int16_t left[AUDIO_BLOCK];
int16_t right[AUDIO_BLOCK];

// --- Heavy hashes (inputs) ---
#define HV_NOTEIN_HASH       0x67E37CA3
#define HV_CTLIN_HASH        0x41BE0F9C
#define HV_POLYTOUCHIN_HASH  0xBC530F59
#define HV_PGMCHANGEIN_HASH  0x2E1EA03D
#define HV_TOUCHIN_HASH      0x553925BD
#define HV_BENDIN_HASH       0x3083F0F7
#define HV_MIDIIN_HASH       0x149631BE
#define HV_MIDIREALTIMEIN_HASH 0x6FFF0BCF

// --- Heavy hashes (outputs) ---
#define HV_NOTEOUT_HASH      0xD1D4AC2
#define HV_CTL_OUT_HASH      0xE5E2A040
#define HV_POLYTOUCHOUT_HASH 0xD5ACA9D1
#define HV_PGMCHANGEOUT_HASH 0x8753E39E
#define HV_TOUCHOUT_HASH     0x476D4387
#define HV_BENDOUT_HASH      0xE8458013
#define HV_MIDIOUT_HASH      0x6511DE55
#define HV_MIDIOUTPORT_HASH  0x165707E4

// --- Objects ---
I2S i2s_output(OUTPUT);
Heavy_oscilator pd_prog(SAMPLE_RATE);
Adafruit_USBD_MIDI usb_midi;

// --- Potentiometer volume ---
// #define VOL_PIN A0
// float volume = 1.0f;
// int lastPot = -1;

// --- Heavy → USB MIDI callback ---
void heavyMidiOutHook(HeavyContextInterface *c, const char *receiverName, hv_uint32_t receiverHash, const HvMessage *m) {
    uint8_t channel = 0; // MIDI channel 1
    uint8_t midiMsg[3];

    if(receiverHash == HV_NOTEOUT_HASH) {
        int note = (int)msg_getFloat(m, 0);
        int velocity = (int)msg_getFloat(m, 1);
        midiMsg[0] = velocity>0 ? (0x90 | channel) : (0x80 | channel);
        midiMsg[1] = note;
        midiMsg[2] = velocity>0 ? velocity : 0;
    }
    else if(receiverHash == HV_CTL_OUT_HASH) {
        int cc = (int)msg_getFloat(m, 0);
        int val = (int)msg_getFloat(m, 1);
        midiMsg[0] = 0xB0 | channel;
        midiMsg[1] = cc;
        midiMsg[2] = val;
    }
    else if(receiverHash == HV_POLYTOUCHOUT_HASH) {
        int note = (int)msg_getFloat(m, 0);
        int val  = (int)msg_getFloat(m, 1);
        midiMsg[0] = 0xA0 | channel;
        midiMsg[1] = note;
        midiMsg[2] = val;
    }
    else if(receiverHash == HV_PGMCHANGEOUT_HASH) {
        int prog = (int)msg_getFloat(m, 0);
        midiMsg[0] = 0xC0 | channel;
        midiMsg[1] = prog;
        midiMsg[2] = 0;
    }
    else if(receiverHash == HV_TOUCHOUT_HASH) {
        int val = (int)msg_getFloat(m, 0);
        midiMsg[0] = 0xD0 | channel;
        midiMsg[1] = val;
        midiMsg[2] = 0;
    }
    else if(receiverHash == HV_BENDOUT_HASH) {
        int val = (int)msg_getFloat(m, 0);
        midiMsg[0] = 0xE0 | channel;
        midiMsg[1] = val & 0x7F;
        midiMsg[2] = (val >> 7) & 0x7F;
    }
    else if(receiverHash == HV_MIDIOUT_HASH || receiverHash == HV_MIDIOUTPORT_HASH) {
        int val1 = (int)msg_getFloat(m, 0);
        int val2 = (int)msg_getFloat(m, 1);
        int val3 = (int)msg_getFloat(m, 2);
        midiMsg[0] = val1;
        midiMsg[1] = val2;
        midiMsg[2] = val3;
    } else return;

    if(tud_mounted()) usb_midi.write(midiMsg, 3);
}

// --- USB MIDI → Heavy handler ---
void handleUsbMidi() {
    static uint8_t status=0, data1=0, data2=0, step=0;

    while(usb_midi.available()) {
        int byte = usb_midi.read();
        if(byte < 0) break;

        if(byte & 0x80) { status = byte & 0xF0; step=1; continue; }
        if(step==1) { data1=byte; step=2; continue; }
        if(step==2) {
            data2=byte; step=0;

            switch(status){
                case 0x90: // Note On
                    hv_sendMessageToReceiverFF(&pd_prog, HV_NOTEIN_HASH, 0.0, data1, data2>0?data2:0.0);
                    break;
                case 0x80: // Note Off
                    hv_sendMessageToReceiverFF(&pd_prog, HV_NOTEIN_HASH, 0.0, data1, 0.0);
                    break;
                case 0xB0: // Control Change
                    hv_sendMessageToReceiverFF(&pd_prog, HV_CTLIN_HASH, 0.0, data1, data2);
                    break;
                case 0xA0: // Poly Aftertouch
                    hv_sendMessageToReceiverFF(&pd_prog, HV_POLYTOUCHIN_HASH, 0.0, data1, data2);
                    break;
                case 0xC0: // Program Change
                    hv_sendMessageToReceiverFF(&pd_prog, HV_PGMCHANGEIN_HASH, 0.0, data1, 0.0);
                    break;
                case 0xD0: // Channel Aftertouch
                    hv_sendMessageToReceiverFF(&pd_prog, HV_TOUCHIN_HASH, 0.0, data1, 0.0);
                    break;
                case 0xE0: // Pitch Bend
                    hv_sendMessageToReceiverFF(&pd_prog, HV_BENDIN_HASH, 0.0, (data2<<7)|data1, 0.0);
                    break;
                case 0xF0: // System Realtime (if needed)
                    hv_sendMessageToReceiverFF(&pd_prog, HV_MIDIREALTIMEIN_HASH, 0.0, byte, 0.0);
                    break;
            }
        }
    }
}

// --- Setup ---
void setup() {
    Serial.begin(115200);

    usb_midi.begin();
    while (!TinyUSBDevice.mounted()) delay(10);

    i2s_output.setFrequency(SAMPLE_RATE);
    i2s_output.setDATA(I2S_DATA_PIN);
    i2s_output.setBCLK(I2S_BCLK_PIN);
    i2s_output.setBitsPerSample(16);
    i2s_output.setBuffers(4, AUDIO_BLOCK);
    i2s_output.begin();

    pd_prog.setSendHook(heavyMidiOutHook);

    Serial.println("USB MIDI + Heavy ready!");
}

// --- Main loop ---
void loop() {
    handleUsbMidi();

 //   int potVal = analogRead(VOL_PIN);
 //   if(potVal != lastPot){
 //       lastPot = potVal;
 //       volume = potVal / 4095.0f;
    

    pd_prog.processInlineInterleaved(audioBlock, audioBlock, AUDIO_BLOCK);

    for(int i=0; i<AUDIO_BLOCK; i++){
        left[i]  = int16_t(audioBlock[2*i]   * 32767.0f * volume);
        right[i] = int16_t(audioBlock[2*i+1] * 32767.0f * volume);
    }

    for(int i=0; i<AUDIO_BLOCK; i++){
        i2s_output.write16(left[i], right[i]);
    }
}

