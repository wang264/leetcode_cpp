#include <math.h>


class Solution {
public:
    int mySqrt(int x) {
        if (x==0) {
            return 0;
        }
        // f(x) = x^2 - n
        // f'(x) = 2*x
        double x_0=x/2.0;
        double diff =3;
        while (diff>0.1) {
            double old_x = x_0;
            double fx = x_0*x_0 - x;
            double f_prime_x = 2*x_0;
            x_0 = x_0 - fx / f_prime_x;
            diff = abs(x_0 - old_x);
        }
        return static_cast<int>(x_0);
    }
};