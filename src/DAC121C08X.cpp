/* DAC121C08X library by David H Hagan
 */

#include "application.h"
#include "DAC121C08X.h"


DAC121C08X::DAC121C08X(uint8_t ADDR, float VREF)
{
  _ADDR = ADDR;
  _VREF = VREF;
  _NBITS = 4095;    // Total number of bits on a 12-bit DAC
}


void DAC121C08X::begin()
{
    if (!Wire.isEnabled()) {
      Wire.begin();
    }

    return;
}

bool DAC121C08X::write_value(unsigned int val)
{
    if (val > 4095) {
      return false;
    }

    // Begin the I2C Transmission
    Wire.beginTransmission(_ADDR);

    // Write the MSB
    Wire.write(val >> 8);

    // Write the LSB
    Wire.write(val & 0x00FF);

    // End the Transmission
    Wire.endTransmission();

    return true;
}


bool DAC121C08X::write_voltage(float voltage)
{
    unsigned int _val;

    if (voltage > _VREF) {
      return false;
    }

    _val = (voltage / _VREF) * _NBITS;

    return write_value(_val);
}
