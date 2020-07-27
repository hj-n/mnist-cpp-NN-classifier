#include "input_hidden.h"

void Input_Hidden :: backprop(double* delta) {
    for(int i = 0; i < output_num; i++) {
        perceptron_array[i]->backprop(sigmoid_array[i]->backprop() * delta[i], current_input);
    }
}