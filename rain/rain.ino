/*
 * Rain and wind synthesizer. Original patch by Simple Trax and Taavi Viikman.
 * https://youtu.be/ZXwk8sDts0Y
 *
 * Adapted for Heavy compiler by Ledlaux.
 *
 * This code creates USB MIDI device. Send MIDI CC messages to control generator parameters:
 * CC 7  – volume
 * CC 10 – cracles
 * CC 11 – dropamount
 * CC 12 – hipass
 * CC 13 – intensity
 * CC 14 – wind
 * CC 15 – dropgain
 * CC 16 – dropsize
 * CC 17 – size
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
#define I2S_DATA_PIN 9
#define I2S_BCLK_PIN 10
#define I2S_BUFFERS 6
#define I2S_WORDS 258
#define SAMPLE_RATE 22050

// --- Heavy & I2S ---
Heavy_oscilator pd_prog(SAMPLE_RATE);
I2S i2s_output(OUTPUT);

float samples[2 * I2S_WORDS];
int16_t left_buffer[I2S_WORDS];
int16_t right_buffer[I2S_WORDS];

bool cc_initialized = false;

// --- Heavy receiver hashes ---
#define HV_CRACLES_HASH     0x7924B13C
#define HV_HIP_HASH         0x474D7361
#define HV_HIPASS_HASH      0xF8569716
#define HV_DROPAMOUNT_HASH  0x86883492
#define HV_INTENSITY_HASH   0x3D836879
#define HV_WIND_HASH        0xAE05860F
#define HV_DROPGAIN_HASH    0xE480BBEA
#define HV_DROPSIZE_HASH    0x3EC7528A
#define HV_SIZE_HASH        0x4AD2D14C

Adafruit_USBD_MIDI usb_midi;

// --- Volume control ---
float volume = 0.9f;

// --- CC router ---
void routeCC(uint8_t cc, uint8_t val) {
    if (val < 1) val = 1;
    if (val > 127) val = 127;

    float midiVal = float(val);

    switch(cc) {
        case 10: hv_sendMessageToReceiverV(&pd_prog, HV_CRACLES_HASH, 0.0, "f", midiVal); break;
        case 11: hv_sendMessageToReceiverV(&pd_prog, HV_DROPAMOUNT_HASH, 0.0, "f", midiVal); break;
        case 12: hv_sendMessageToReceiverV(&pd_prog, HV_HIPASS_HASH, 0.0, "f", midiVal); break;
        case 13: hv_sendMessageToReceiverV(&pd_prog, HV_INTENSITY_HASH, 0.0, "f", midiVal); break;
        case 14: hv_sendMessageToReceiverV(&pd_prog, HV_WIND_HASH, 0.0, "f", midiVal); break;
        case 15: hv_sendMessageToReceiverV(&pd_prog, HV_DROPGAIN_HASH, 0.0, "f", midiVal); break;
        case 16: hv_sendMessageToReceiverV(&pd_prog, HV_DROPSIZE_HASH, 0.0, "f", midiVal); break;
        case 17: hv_sendMessageToReceiverV(&pd_prog, HV_SIZE_HASH, 0.0, "f", midiVal); break;
        case 7:
            volume = val / 127.0f; // CC#7 volume
            break;
    }
}

// --- USB MIDI handler ---
void handleUsbMidi() {
    static uint8_t status = 0, d1 = 0, d2 = 0, step = 0;

    while (usb_midi.available()) {
        int b = usb_midi.read();
        if (b < 0) break;

        if (b & 0x80) {
            status = b & 0xF0;
            step = 1;
            continue;
        }
        if (step == 1) {
            d1 = b;
            step = 2;
            continue;
        }
        if (step == 2) {
            d2 = b;
            step = 0;
            if (status == 0xB0) routeCC(d1, d2); // Only CC messages
        }
    }
}

// --- Setup ---
void setup() {
    usb_midi.begin();

    i2s_output.setFrequency(SAMPLE_RATE);
    i2s_output.setDATA(I2S_DATA_PIN);
    i2s_output.setBCLK(I2S_BCLK_PIN);
    i2s_output.setBitsPerSample(16);
    i2s_output.setBuffers(I2S_BUFFERS, I2S_WORDS);
    i2s_output.begin();
}

// --- Main loop ---
void loop() {
    handleUsbMidi();

    // Process audio
    pd_prog.processInlineInterleaved(samples, samples, I2S_WORDS);

    for (uint32_t i = 0; i < I2S_WORDS; i++) {
        left_buffer[i]  = int16_t(samples[2 * i] * 32767.0f * volume);
        right_buffer[i] = int16_t(samples[2 * i + 1] * 32767.0f * volume);
        i2s_output.write16(left_buffer[i], right_buffer[i]);
    }

    // Send initial CC values once after Heavy is ready
    if (!cc_initialized) {
        hv_sendMessageToReceiverV(&pd_prog, HV_CRACLES_HASH, 0.0, "f", 20.0f);
        hv_sendMessageToReceiverV(&pd_prog, HV_HIPASS_HASH, 0.0, "f", 50.0f);
        hv_sendMessageToReceiverV(&pd_prog, HV_INTENSITY_HASH, 0.0, "f", 40.0f);
        hv_sendMessageToReceiverV(&pd_prog, HV_WIND_HASH, 0.0, "f", 20.0f);
        hv_sendMessageToReceiverV(&pd_prog, HV_DROPGAIN_HASH, 0.0, "f", 60.0f);
        hv_sendMessageToReceiverV(&pd_prog, HV_DROPSIZE_HASH, 0.0, "f", 30.0f);
        hv_sendMessageToReceiverV(&pd_prog, HV_SIZE_HASH, 0.0, "f", 50.0f);
        hv_sendMessageToReceiverV(&pd_prog, HV_DROPAMOUNT_HASH, 0.0, "f", 30.0f);

        cc_initialized = true;
    }
}
