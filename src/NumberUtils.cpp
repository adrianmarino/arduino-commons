#include "NumberUtils.h"

bool between(float value, float min, float max) {
    return value >= min && value <=max;
}

bool between(float value, float limit) {
    return between(value, -limit, limit);
}