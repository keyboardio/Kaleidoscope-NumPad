#pragma once

#include "Kaleidoscope-LEDControl.h"
#include "Kaleidoscope-Macros.h"
#include "LEDUtils.h"

class NumPad_ : public KaleidoscopePlugin {
 public:
  NumPad_(void) {}

  void begin(void) final;

  static uint8_t numPadLayer;
  static cRGB numpad_color;

 private:
  static void loopHook(const bool postClear);

  static byte row, col;
  static bool cleanupDone;
};

class FuncPad_ : public KaleidoscopePlugin {
 public:
  FuncPad_(void) {}

  void begin(void) final;

  static uint8_t FuncPadLayer;
  static cRGB Funcpad_color;

 private:
  static void loopHook(const bool postClear);

  static byte row, col;
  static bool cleanupDone;
};

extern NumPad_ NumPad;
extern FuncPad_ FuncPad;

