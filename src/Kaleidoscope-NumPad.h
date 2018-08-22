#pragma once

#include "Kaleidoscope-LEDControl.h"
#include "Kaleidoscope-Macros.h"
#include "LEDUtils.h"

class NumPad_ : public kaleidoscope::Plugin {
 public:
  NumPad_(void) {}

  static uint8_t numPadLayer;

  static bool ledEffect;
  static cRGB color;
  static uint8_t lock_hue;

  kaleidoscope::EventHandlerResult onSetup(void);
  kaleidoscope::EventHandlerResult afterEachCycle();

 private:
  static byte lock_row, lock_col;
  static bool cleanupDone;
  static bool originalNumLockState;
};

extern NumPad_ NumPad;
