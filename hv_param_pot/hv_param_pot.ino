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


// -------------------- Setup --------------------
void setup() {
  // --- I2S output setup ---
  i2s_output.setFrequency(SAMPLE_RATE);        
  i2s_output.setDATA(I2S_DATA_PIN);            
  i2s_output.setBCLK(I2S_BCLK_PIN);            
  i2s_output.setBitsPerSample(16);             
  i2s_output.setBuffers(I2S_BUFFERS, I2S_WORDS); 
  i2s_output.begin();                           
                 

  // --- Potentiometer setup ---
  pinMode(FREQ_POT_PIN, INPUT);               
               
}

// -------------------- Main loop --------------------
void loop() {

int potVal = analogRead(FREQ_POT_PIN);       // 0–4095 
int midiVal = 1 + (potVal * 126) / 1000;     // map to 1–127
hv_sendMessageToReceiverV(&pd_prog, 0x345FC008, 0.0, "f", (float)midiVal);   //Hash number from Heavy_oscilator.cpp

  // Process audio
  pd_prog.processInlineInterleaved(samples, samples, I2S_WORDS);

  for (uint32_t i = 0; i < I2S_WORDS; i++) {
    left_buffer[i]  = int16_t(samples[2*i]   * 32767.0f);
    right_buffer[i] = int16_t(samples[2*i+1] * 32767.0f);
    i2s_output.write16(right_buffer[i], left_buffer[i]);
  }
}
