# Polyphonic MIDI

This folder contains examples of **polyphonic USB MIDI input** implementation in Pure Data Heavy compiled patches using the TinyUSB stack.

The first example implements **custom voice allocation directly in the Arduino code**.  
For each `[r Note]` object, a unique hash index is assigned. These hashes are defined in `Heavy_oscillator.cpp`:

```cpp
constexpr hv_uint32_t VOICE_HASHES[MAX_VOICES] = {
    0x3E185FE5, // NOTE1
    0x3C682D20, // NOTE2
    0xC430EA70, // NOTE3
    0xD3ABA527  // NOTE4
};
```
Second example patch uses the built-in **[poly~]** object to manage individual audio voices (4 voice max).
