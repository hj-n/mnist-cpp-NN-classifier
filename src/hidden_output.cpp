#include "hidden_output.h"

double* Hidden_Output :: backprop(double* delta) {

    double* next_delta = new double[input_num];
    for(int i = 0; i < input_num; i++) {
        next_delta[i] = 0;
    }
    for(int i = 0; i < output_num; i++) {
        double* current_perceptron_weight = perceptron_array[i]->backprop(sigmoid_array[i]->backprop() * delta[i], current_input);
        for(int j = 0; j < input_num; j++) {
            next_delta[j] += current_perceptron_weight[j] * delta[i];
        }
    }

    return next_delta;
}