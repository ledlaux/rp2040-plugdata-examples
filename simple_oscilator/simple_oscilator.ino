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

#define I2S_DATA_PIN  9
#define I2S_BCLK_PIN  10

#define I2S_BUFFERS   4
#define I2S_WORDS     64
#define SAMPLE_RATE   44100

  I2S i2s_output(OUTPUT);
  Heavy_oscilator pd_prog(SAMPLE_RATE);

  float samples[2 * I2S_WORDS];
  int16_t left_buffer[I2S_WORDS];
  int16_t right_buffer[I2S_WORDS];

void setup() {
  i2s_output.setFrequency(SAMPLE_RATE);  // sets sample rate
  i2s_output.setDATA(I2S_DATA_PIN);      // DATA pin
  i2s_output.setBCLK(I2S_BCLK_PIN);      // BCLK pin
  i2s_output.setBitsPerSample(16);       // 16-bit audio
  i2s_output.setBuffers(I2S_BUFFERS, I2S_WORDS); // buffer settings
  i2s_output.begin();                    // just call without arguments
}

void loop() {

  pd_prog.processInlineInterleaved(samples, samples, I2S_WORDS);

  for (uint32_t i = 0; i < I2S_WORDS; i++) {
    
    left_buffer[i]  = int16_t(samples[2*i] * 32767.0f);
    right_buffer[i] = int16_t(samples[2*i+1] * 32767.0f);
    i2s_output.write16(right_buffer[i], left_buffer[i]);

  }

}
