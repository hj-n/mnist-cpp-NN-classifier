#include <cmath>
#include "sigmoid.h"

double Sigmoid :: forward(double input) {
    current_output = 1.0 / (1.0 + exp(-(input)));
    return current_output;
}

double Sigmoid :: backprop() {
    return current_output * (1 - current_output);
}