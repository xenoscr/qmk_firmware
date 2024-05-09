# erglodox76

![erglodox76](imgur.com image replace me!)

A Ergodox variant based on the [Ergo72](https://github.com/Emeryth/Ergo72) by [Emeryth](https://github.com/Emeryth). I have made some changes to Emeryth's design and added RGB support via Adafruit's [NeoPixel-2020](https://www.adafruit.com/product/4684) that utilize the WS2818B protocol.

* Keyboard Maintainer: [Conor Richard](https://github.com/xenoscr)
* Hardware Supported: STM32F072C8T6
* Hardware Availability: *Links to where you can find this hardware*

Make example for this keyboard (after setting up your build environment):

    make erglowdox76:default

Flashing example for this keyboard:

    make erglowdox76:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader:

* **Physical Jumper**: Move the jumper from "RUN" to "BOOT".
