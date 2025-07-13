#include "I2CMultiplexor.h"

void I2CMultiplexor::selectChannel(uint8_t channel)
{
    if (channel > 7)
        return;
    Wire.beginTransmission(addess);
    Wire.write(1 << channel);
    Wire.endTransmission();
}