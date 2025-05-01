#include "ex5.h"
//
// TrapezoidalIntegration: calculate and return S(T) using the Einstein model and trapezoid integration
//                         (arguments: temperature, Einstein temperature, gas constant, number of trapezoid
//                         intervals to use) [the function definition is in file ex5_integ.cc]
//
double TrapezoidalIntegration(double T, double T_E, double R, int N) {
    cout << "# TrapezoidalIntegration was called!" << endl;
    // sum to add up the area in
    double sum = 0.0;
    // variable for the first edge of the trapez
    double value_1 = 0.0;
    // variable for the second edge of the trapez
    double value_2 = 0.0;
    // variable for the first temperature
    double T_1 = 0.0;
    // variable for the second temperature
    double T_2 = 0.0;

    // loop to calculate the area of each slice
    for (int i = 0; i < N; i++) {
        // calculate T1 and T2 for the values
        T_1 = i*(T/double(N));
        T_2 = (i+1)*(T/double(N));
        // scale_by_T = true to calculate cv(T)/T as needed
        value_1 = CalculateHeatCapacity(true, T_1, T_E, R);
        value_2 = CalculateHeatCapacity(true, T_2, T_E, R);
        // calculate the area and add it to the sum
        sum += (T_2-T_1)/2.0*(value_1+value_2);
    }
    cout << "# TrapezoidalIntegration returned sum = " << sum << endl;
    return sum;
}

// MontecarloIntegration: calculate and return S(T) using the Einstein model and Monte Carlo integration
//                   (arguments: temperature, Einstein temperature, total number of trial points to
//                   use for the integration, random-number generator seed, number of trial points
//                   found under the curve, T and c_V(T)/T coordinates of these points) [the function
//                   definition is in file ex5_integ.cc]
//                   Remark: the rectangle to sample with trial points has a height given by
//                   max_cv_over_T (macro in ex5.h)
//
double MontecarloIntegration(double T, double T_E, double R, int N, int& seed, int& num_hits, double table[][2]) {
    cout << "# MontecarloIntegration was called!" << endl;
    // variable for the area
    double area = 0.0;
    // make variables for the random koordinates
    double xn = 0.0;
    double yn = 0.0;
    // variable for the real cv(T)/T value for xn
    double compare_yn = 0.0;
    double num_hit = 0.0;
    // autism.
    double H = max_cv_over_T;
    // loop over the number of steps
    for (int i = 0; i < N; i++) {
        // get the random coordinates
        xn = GetRandomNumber(seed);
        yn = GetRandomNumber(seed);
        // scale the coordinates
        xn = xn * T;
        yn = yn * H;
        // calculate the cv(T)/T value for xn
        compare_yn = CalculateHeatCapacity(true, xn, T_E, R);
        // check if it is a hit
        if (compare_yn > yn) {
            num_hits += 1.0;
            table[num_hits][0] = xn;
        	table[num_hits][1] = yn;
        }
    }
    area = (H*T*double(num_hits))/double(N);
    return area;
}
//
// RombergIntegration: calculate and return S(T) using the Einstein model and Romberg integration
//               (arguments: temperature, Einstein temperature, gas constant, order of the Romberg
//               integration) [the function definition is in file ex5_integ.cc]
//
double RombergIntegration(double TT, double T_E, double R, int L_max) {
  cout << "# RombergIntegration was called!" << endl;
  // @ For task C: remove the next line and replace it by your code!
  cout << "# ... but for now it does nothing (merely returns a big zero!)" << endl;
  return 0.0;
}
