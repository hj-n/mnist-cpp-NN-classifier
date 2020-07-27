
#include "bridge.h"
#include "constants.h"
#include "bridge.h"

Bridge :: Bridge(int input_num, int output_num) {
    this->input_num = input_num;
    this->output_num = output_num;
    current_input = new double[input_num];

    perceptron_array = new Perceptron*[output_num];
    sigmoid_array = new Sigmoid*[output_num];
    for(int i = 0; i < output_num; i++) {
        perceptron_array[i] = new Perceptron(input_num);
        sigmoid_array[i] = new Sigmoid;
    }

}

double* Bridge :: forward(double* input) {
    for(int i = 0; i < input_num; i++) current_input[i] = input[i];

    double* result = new double[output_num];
    for(int i = 0; i < output_num; i++) 
        result[i] = sigmoid_array[i]->forward(perceptron_array[i]->forward(current_input));
    
    return result;
}