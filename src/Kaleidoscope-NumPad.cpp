#include "Kaleidoscope-NumPad.h"
#include "LEDUtils.h"
#include "Kaleidoscope.h"
#include "layers.h"

byte NumPad_::lock_row = 255, NumPad_::lock_col = 255;
uint8_t NumPad_::numPadLayer;
bool NumPad_::cleanupDone = true;
bool NumPad_::originalNumLockState = false;

bool NumPad_::ledEffect = true;
cRGB NumPad_::color = CRGB(160, 0, 0);
uint8_t NumPad_::lock_hue = 170;

kaleidoscope::EventHandlerResult NumPad_::onSetup(void) {
  originalNumLockState = !!(kaleidoscope::hid::getKeyboardLEDs() & LED_NUM_LOCK);
  return kaleidoscope::EventHandlerResult::OK;
}

static bool getNumlockState() {
  return !!(kaleidoscope::hid::getKeyboardLEDs() & LED_NUM_LOCK);
}

static void syncNumlock(bool state) {
  bool numState = getNumlockState();
  if (numState != state) {
    kaleidoscope::hid::pressKey(Key_KeypadNumLock);
  }
}

kaleidoscope::EventHandlerResult NumPad_::afterEachCycle() {
  if (!Layer.isOn(numPadLayer)) {
    bool numState = getNumlockState();
    if (!cleanupDone) {
      LEDControl.set_mode(LEDControl.get_mode_index());

      if (!originalNumLockState) {
        syncNumlock(false);
        numState = false;
      }
      cleanupDone = true;
    }
    originalNumLockState = numState;

    return kaleidoscope::EventHandlerResult::OK;
  }

  cleanupDone = false;
  syncNumlock(true);

  if (!ledEffect)
    return kaleidoscope::EventHandlerResult::OK;

  LEDControl.set_mode(LEDControl.get_mode_index());

  for (uint8_t r = 0; r < ROWS; r++) {
    for (uint8_t c = 0; c < COLS; c++) {
      Key k = Layer.lookupOnActiveLayer(r, c);
      Key layer_key = Layer.getKey(numPadLayer, r, c);

      if (k == LockLayer(numPadLayer)) {
        lock_row = r;
        lock_col = c;
      }

      if ((k != layer_key) || (k == Key_NoKey) || (k.flags != KEY_FLAGS)) {
        LEDControl.refreshAt(r, c);
      } else {
        LEDControl.setCrgbAt(r, c, color);
      }
    }
  }

  if (lock_row > ROWS || lock_col > COLS)
    return kaleidoscope::EventHandlerResult::OK;

  cRGB lock_color = breath_compute(lock_hue);
  LEDControl.setCrgbAt(lock_row, lock_col, lock_color);

  return kaleidoscope::EventHandlerResult::OK;
}

NumPad_ NumPad;
