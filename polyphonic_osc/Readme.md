This example demonstrates **polyphonic oscillators** in Pure Data, using USB MIDI input **[notein]** with custom voice allocation implemented directly in the Arduino code.



> Note: The **[poly~]** object, normally used for polyphonic input in PD, is not functional on RP2040 when using Heavy-compiled code.



Each note is assigned a unique hash index, defined in `Heavy_oscillator.cpp`:


```cpp
constexpr hv_uint32_t VOICE_HASHES[MAX_VOICES] = {
    0x3E185FE5, // NOTE1
    0x3C682D20, // NOTE2
    0xC430EA70, // NOTE3
    0xD3ABA527  // NOTE4
};
