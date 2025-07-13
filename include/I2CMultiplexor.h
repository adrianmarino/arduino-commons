#pragma once
#include <Arduino.h>
#include <Wire.h>

const int I2C_MUX_DEFAULT_ADDRESS = 0x70;

class I2CMultiplexor {

private:
    const int addess;

public:
    I2CMultiplexor(int addess = I2C_MUX_DEFAULT_ADDRESS) : addess(addess) {}

    void selectChannel(uint8_t channel);
};
