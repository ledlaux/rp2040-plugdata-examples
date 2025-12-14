/*
 * This example creates a utility device for Novation Circuit Tracks chromatic sample playback.
 * Send MIDI notes to the "RP2040 Zero" USB MIDI device and route its output to Circuit Tracks MIDI channel 10.
 *
 * Copyright (c) 2025 Vadims Maksimovs (ledlaux)
 *
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

// --- Heavy hashes (outputs) ---
#define HV_NOTEOUT_HASH      0xD1D4AC2
#define HV_CTL_OUT_HASH      0xE5E2A040

// --- Objects ---
I2S i2s_output(OUTPUT);
Heavy_oscilator pd_prog(SAMPLE_RATE);
Adafruit_USBD_MIDI usb_midi;

// --- Heavy → USB MIDI callback ---
void heavyMidiOutHook(HeavyContextInterface *c, const char *receiverName, hv_uint32_t receiverHash, const HvMessage *m) {
    uint8_t midiMsg[3] = {0, 0, 0};
    int humanChannel = 1; // default, will take from PD
    int zeroBasedCh  = 0;

    if(msg_getNumElements(m) >= 3)
        humanChannel = (int)msg_getFloat(m, 2) + 1; // PD sends 0-based, convert to 1-based

    if(humanChannel < 1) humanChannel = 1;
    if(humanChannel > 16) humanChannel = 16;
    zeroBasedCh = humanChannel - 1;

    switch(receiverHash) {
        case HV_NOTEOUT_HASH: {
            int note     = (int)msg_getFloat(m, 0);
            int velocity = (int)msg_getFloat(m, 1);

            midiMsg[0] = velocity > 0 ? (0x90 | (zeroBasedCh & 0x0F))
                                      : (0x80 | (zeroBasedCh & 0x0F));
            midiMsg[1] = note & 0x7F;
            midiMsg[2] = velocity > 0 ? (velocity & 0x7F) : 0;

        //    Serial.printf("NoteOut → human ch:%d zero-based ch:%d note:%d vel:%d\n", humanChannel, zeroBasedCh, note, velocity);
            break;
        }

        case HV_CTL_OUT_HASH: {
            int val = (int)msg_getFloat(m, 0);
            int cc  = (int)msg_getFloat(m, 1);

            if(val < 0) val = 0;
            if(val > 127) val = 127;
            if(cc < 0) cc = 0;
            if(cc > 127) cc = 127;

            midiMsg[0] = 0xB0 | (zeroBasedCh & 0x0F);
            midiMsg[1] = cc & 0x7F;
            midiMsg[2] = val & 0x7F;

        //    Serial.printf("CCOut → human ch:%d zero-based ch:%d cc:%d val:%d\n", humanChannel, zeroBasedCh, cc, val);
            break;
        }
    }

    if(tud_mounted())
        usb_midi.write(midiMsg, 3);
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
                case 0x90: hv_sendMessageToReceiverFF(&pd_prog, HV_NOTEIN_HASH, 0.0, data1, data2>0?data2:0.0); break;
                case 0x80: hv_sendMessageToReceiverFF(&pd_prog, HV_NOTEIN_HASH, 0.0, data1, 0.0); break;
                case 0xB0: hv_sendMessageToReceiverFF(&pd_prog, HV_CTLIN_HASH, 0.0, data1, data2); break;
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

    pd_prog.processInlineInterleaved(audioBlock, audioBlock, AUDIO_BLOCK);

    for(int i=0; i<AUDIO_BLOCK; i++){
        left[i]  = int16_t(audioBlock[2*i]   * 32767.0f * volume);
        right[i] = int16_t(audioBlock[2*i+1] * 32767.0f * volume);
    }

    for(int i=0; i<AUDIO_BLOCK; i++){
        i2s_output.write16(left[i], right[i]);
    }
}
