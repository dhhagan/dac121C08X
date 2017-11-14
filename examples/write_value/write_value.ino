// Example usage for DAC121C08X library by David H Hagan.

#include "DAC121C08X.h"

// Initialize objects from the lib
DAC121C08X dac(0x09, VREF=5.0);

void setup() {
    // Call functions on initialized library objects that require hardware
    dac.begin();
}

void loop() {
    for (int i=0; i<4095; i++) {
      dac.write_value(i);

      delay(1000);
    }
}
