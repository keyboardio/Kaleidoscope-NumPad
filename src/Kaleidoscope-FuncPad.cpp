#include "Kaleidoscope-FuncPad.h"
#include "LEDUtils.h"
#include "Kaleidoscope.h"
#include "layers.h"

byte FuncPad_::row = 255, FuncPad_::col = 255;
uint8_t FuncPad_::FuncPadLayer;
bool FuncPad_::cleanupDone = true;
cRGB Funcpad_color = CRGB(0,0, 100);

void FuncPad_::begin(void) {
  Kaleidoscope.useLoopHook(loopHook);
}

void FuncPad_::loopHook(bool postClear) {
  if (!postClear)
    return;

  if (!Layer.isOn(FuncPadLayer)) {
    if (!cleanupDone) {
      LEDControl.set_mode(LEDControl.get_mode_index());
      cleanupDone = true;
    }
    return;
  }

  cleanupDone = false;
  bool FuncState = !!(kaleidoscope::hid::getKeyboardLEDs() & LED_NUM_LOCK);
  if (!FuncState) {
    kaleidoscope::hid::pressKey(Key_KeypadNumLock);
  }

  LEDControl.set_mode(LEDControl.get_mode_index());

  for (uint8_t r = 0; r < ROWS; r++) {
    for (uint8_t c = 0; c < COLS; c++) {
      Key k = Layer.lookupOnActiveLayer(r, c);
      Key layer_key = Layer.getKey(FuncPadLayer, r, c);

      if (k == LockLayer(FuncPadLayer)) {
        row  = r;
        col = c;
      }

      if ((k != layer_key) || (k.flags != KEY_FLAGS)) {
        LEDControl.refreshAt(r, c);
      } else {
        LEDControl.setCrgbAt(r, c, Funcpad_color);
      }
    }
  }

  if (row > ROWS || col > COLS)
    return;

  cRGB color = breath_compute();
  LEDControl.setCrgbAt(row, col, color);
}

FuncPad_ FuncPad;
