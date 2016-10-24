#include "box.hpp"

// Calculations
double Box::calcArea() {
    return (2 * length * depth) + (2 * width * depth) + (2 * width * length);
}

double Box::calcVolume() {
    return length * width * depth;
}
