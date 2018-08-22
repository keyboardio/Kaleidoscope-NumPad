# Kaleidoscope-NumPad

This is a plugin for [Kaleidoscope][fw] that takes care of handling the HID
numlock toggling when switching to the numpad layer. It also adds a
numpad-specific LED effect, which can be disabled if not desired.

## Using the extension

To use the plugin, include the header, and tell the firmware to use it:

```c++
#include "Kaleidoscope-NumPad.h"

KALEIDOSCOPE_INIT_PLUGINS(NumPad);

void setup() {
  Kaleidoscope.setup();

  NumPad.color = CRGB(0, 0, 160); // a blue color
  NumPad.lock_hue = 85; // green
}
```

##   Plugin properties

The plugin provides the `NumPad` object, with the following properties:

### `.color`

> This property sets the color that the NumPad keys are highlighted in.
>
> The default is `CRGB(160, 0, 0)`, a red color.

### `.lock_hue`

> This property sets the color hue that the NumLock LED breathes in.
>
> The default is `170`, a blue hue.

### `.ledEffect`

> This property controls whether the above color effects are enabled or not.
> You may wish to disable them if you simply don't want them, or if you wish to
> use some other plugin (such as ColorMap) to handle them. Note that this plugin
> may still be required to handle the HID numlock toggling.

 [fw]: https://github.com/keyboardio/Kaleidoscope
