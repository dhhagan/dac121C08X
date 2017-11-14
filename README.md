# DAC121C08X

A Particle library for the [DAC121C08X](http://www.ti.com/product/DAC121C085?)

## Welcome to your library!

Ever need to add more than one 12-bit DAC IC's to your board? Or, is the 3.3V max on the on-board DAC not quite what you're looking for? Look no further! Add up to 8 12-bit micropower DAC with an external reference at once using Texas Instruments' DAC121C085 chip!

To hook up, simply grab an 8VSSOP breakout board from Adafruit/Sparkfun/Digikey/Mouser and get started!


## Usage

Connect the DAC hardware, add the DAC121C08X library to your project and follow this simple example:

```
#include "DAC121C08X.h"

DAC121C08X dac(0x09);

void setup() {
  dac.begin();
}

void loop() {
  for (int i=0;i<4095;i++) {
    dac.write_value(i);   // Increment the DAC value

    delay(1000);
  }
}
```

See the [examples](examples) folder for more details.

## Documentation

There is only one class with two methods in this (ultra) tiny library.

### `DAC121C08X(uint8_t ADDR, float VREF = 5.0)`

To initialize an instance of the class, the only requirement is the i2c address. For this chip, the available addresses include: `0xA`, `0xC`, `0xD`, `0xE`, `0x08`, `0x09`, `0x4C`, `0x4D`, and `0x4E`. For specific details, check out the datasheet.

Optionally, you can provide the reference voltage you have wired up; the default value is 5V.

#### `bool DAC121C08X::write_value(unsigned int val)`

To write a specific value, simply provide an unsigned int between 0-4095 for the 12-bit version. Here, 0 will correspond to 0V and 4095 will correspond to [VREF] volts.

#### `bool DAC121C08X::write_voltage(float voltage)`

Rather than have to calculate the number of bits for the voltage you actually want, use this method to do all the (not very) hard work for you. Simply provide a float between 0 and [VREF] volts.

## Contributing

Here's how you can make changes to this library and eventually contribute those changes back.

To get started, [clone the library from GitHub to your local machine](https://help.github.com/articles/cloning-a-repository/).

Change the name of the library in `library.properties` to something different. You can add your name at then end.

Modify the sources in <src> and <examples> with the new behavior.

To compile an example, use `particle compile examples/usage` command in [Particle CLI](https://docs.particle.io/guide/tools-and-features/cli#update-your-device-remotely) or use our [Desktop IDE](https://docs.particle.io/guide/tools-and-features/dev/#compiling-code).

After your changes are done you can upload them with `particle library upload` or `Upload` command in the IDE. This will create a private (only visible by you) library that you can use in other projects. Do `particle library add DAC121C08X_myname` to add the library to a project on your machine or add the DAC121C08X_myname library to a project on the Web IDE or Desktop IDE.

At this point, you can create a [GitHub pull request](https://help.github.com/articles/about-pull-requests/) with your changes to the original library.

If you wish to make your library public, use `particle library publish` or `Publish` command.

## LICENSE
Copyright 2017 David H Hagan

Licensed under the MIT license
