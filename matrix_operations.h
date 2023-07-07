//
// Created by junior Kondji on 07/07/2023.

#define MATRIXTEMPLATE_MATRIX_OPERATIONS_H
#include "Utilsmatrixtemplate.h"
#include <iostream>

int main() {
    float a = 1.0;
    float b = 1.00001;
    if (isEqual(a, b)) {
        std::cout << "I valori sono uguali" << std::endl;
    } else {
        std::cout << "I valori sono diversi" << std::endl;
    }

    return 0;
}

