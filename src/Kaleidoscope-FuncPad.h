#pragma once

#include "Kaleidoscope-LEDControl.h"
#include "Kaleidoscope-Macros.h"
#include "LEDUtils.h"

class FuncPad_ : public KaleidoscopePlugin {
 public:
  FuncPad_(void) {}

  void begin(void) final;

  static uint8_t FuncPadLayer;

 private:
  static void loopHook(const bool postClear);

  static byte row, col;
  static bool cleanupDone;
};

extern FuncPad_ FuncPad;

