#pragma once
#include <Arduino.h>
#include "pico/multicore.h"

// --- Joystick pins ---
#define PIN_X A1     // Analog pin for X-axis
#define PIN_Y A0     // Analog pin for Y-axis
#define PIN_SW 14    // Digital pin for joystick button (switch)

// --- Settings ---
#define DEADZONE 8       // Ignore small movements near center
#define AXIS_SMOOTH 0.1f // Low-pass filter strength for smoothing

// Struct holding joystick data
struct JoystickState {
    int16_t x = 0;       // Smoothed X-axis value
    int16_t y = 0;       // Smoothed Y-axis value
    bool button = false; // Button pressed = true
};

// Class for handling joystick input
class JoystickInput {
    uint16_t centerX = 2048, centerY = 2048; // Center calibration values
    float smoothX = 0, smoothY = 0;           // Smoothed analog readings

public:
    JoystickState state; // Public struct to hold current joystick state

    // Initialize joystick pins and perform simple calibration
    void begin() {
        analogReadResolution(12);  // 12-bit ADC resolution (0–4095)
        pinMode(PIN_SW, INPUT_PULLUP); // Enable internal pull-up resistor for button

        // Read current position to determine center offset
        centerX = analogRead(PIN_X);
        centerY = analogRead(PIN_Y);
        smoothX = centerX;
        smoothY = centerY;
    }

    // Continuous reading loop (to be run on a core or task)
    void runTask() {
        while (true) {
            // --- Read joystick axes ---
            int rawX = analogRead(PIN_X);
            int rawY = analogRead(PIN_Y);

            // --- Apply exponential smoothing filter ---
            smoothX = AXIS_SMOOTH * rawX + (1 - AXIS_SMOOTH) * smoothX;
            smoothY = AXIS_SMOOTH * rawY + (1 - AXIS_SMOOTH) * smoothY;

            // --- Apply deadzone ---
            // If movement is small (within DEADZONE), set to 0
            state.x = (abs(smoothX - centerX) > DEADZONE) ? (int16_t)smoothX : 0;
            state.y = (abs(smoothY - centerY) > DEADZONE) ? (int16_t)smoothY : 0;

            // --- Read button (active-low) ---
            state.button = !digitalRead(PIN_SW);

            // --- Allow Pico’s background tasks to run ---
            tight_loop_contents();
        }
    }
};
