#pragma once

/* DAC121C08X library by David H Hagan
 */

// This will load the definition for common Particle variable types
#include "Particle.h"

// This is your main class that users will import into their application
class DAC121C08X
{
public:

  DAC121C08X(uint8_t ADDR, float VREF = 5.0);


  void begin();
  bool write_value(unsigned int val);
  bool write_voltage(float voltage);

private:

  uint8_t _ADDR;
  float _VREF;
  unsigned int _NBITS;
};
