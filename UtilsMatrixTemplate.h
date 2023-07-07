//KONDJI NGUIMBOUS JUNIOR 7090449
//

#ifndef MATRIXTEMPLATE_UTILSMATRIXTEMPLATE_H
#define MATRIXTEMPLATE_UTILSMATRIXTEMPLATE_H

#include <cmath>
#include <limits>


template<typename T>
bool isEqual(const T&left, const T&right) {
    return left==right;

}

template<>
bool isEqual<float>(const float&left,const float&right) {
    float epsilon = std::numeric_limits<float>::epsilon();
    return std::fabs(left - right) <= epsilon;

}

#endif //MATRIXTEMPLATE_UTILSMATRIXTEMPLATE_H
