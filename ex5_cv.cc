//
// Heat-capacity calculation function for Ex 5ABC: Entropy of a solid using the Einstein model
//
#include <iostream>

#include "ex5.h"
//
// CalculateHeatCapacity : calculate and return c_V(T) if scale_by_T is false, or c_V(T)/T if scale_by_T is true,
//                         using the Einstein model (arguments: switch to say if we divide by T, temperature,
//                         Einstein temperature, gas constant) [the function definition is in file ex5_cv.cc]
//                         Remark: if X = T/T_E is below min_x (global constant), c_V(T) and c_V(T)/T are
//                         negligible, so the function should set them to zero to avoid divisions by zero
//
double CalculateHeatCapacity(bool scale_by_T, double T, double T_E, double R) {

    cout << "# CalculateHeatCapacity was called!" << endl;
    double x = T/T_E;
    // if x < min_x then return exactily zero to not mess with basic math
    if (x < min_x) {
        return 0.0;
    }

    // calculate cVT
    double cVT = 3.0 * R * ( exp(1.0/x) / ( pow(( x * ( exp(1.0/x) - 1.0) ), 2.0) ) );

    if (scale_by_T) {
        // return cv(T)/T
        return cVT / T;
    } else if (!scale_by_T) {
        // return cv(T)
        return cVT;
    }
    return 0.0;

}