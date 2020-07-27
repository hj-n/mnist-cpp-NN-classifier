#include <cstdlib>
#include <ctime>

#include "constants.h"
#include "helper.h"

void random_init() {
    srand(static_cast<unsigned int>(std::time(0)));
}

double rand_0to1() {
    return ((rand() % 10000) * 0.0001 - 0.5) * 8;
}

double loss_function(double* delta) {
    double loss = 0.0;
    for(int i = 0; i < OUTPUT_NUM; i++) {
        loss += delta[i] * delta[i];
    }
    return loss * 0.5;
}
