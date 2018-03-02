# Kaleidoscope-NumPad
# Kaleidoscope-FuncPad

This is a plugin for [Kaleidoscope][fw], that adds a NumPad-specific LED And a FuncPad for another layer
effect, along with a way to toggle to a numpad layer, and apply the effect.

Usage:
in your "Model01-Firmware.ino"

replace line: NumPad.numPadLayer = NUMPAD;

By :

NumPad.numPadLayer = NUMPAD;
NumPad.numpad_color = CRGB(200, 0, 0);
//set the ledcolor for the function
FuncPad.FuncPadLayer = FUNCTION;  //layer you want to be light up
FuncPad.Funcpad_color = CRGB(0, 0, 200);

replace line:
// The numpad plugin is responsible for lighting up the 'numpad' mode with a custom LED effect
    &NumPad,
by :

// The numpad plugin is responsible for lighting up the 'numpad' mode with a custom LED effect
    &NumPad,
    &FuncPad,
    
    
 [fw]: https://github.com/keyboardio/Kaleidoscope
