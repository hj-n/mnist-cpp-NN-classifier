#include <cstdlib>

#include "perceptron.h"
#include "constants.h"
#include "helper.h"
#include <iostream>

using namespace std;

Perceptron :: Perceptron(int num) {
    this->num = num;
    this->weight = new double[num];
    for(int i = 0; i < num; i++) {
        weight[i] = rand_0to1();
    }
    this->bias = rand_0to1();

    
}


double Perceptron :: forward(double* input) {
    double output = 0;
    for(int i = 0; i < num; i++) {
        output += weight[i] * input[i];
    }
    output += bias;
    return output;
}

double* Perceptron :: backprop(double delta, double* current_input) {
    for(int i = 0; i < num; i++) {
        weight[i] -= LR * delta * current_input[i];
    }
    bias -= LR * delta;

    return weight;
}