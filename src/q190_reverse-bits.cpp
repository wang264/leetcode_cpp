#include <stdint.h>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret=0;
        int power=31;
        
        while(n!=0) {
            bool right_most_bit = (n&1);
            uint32_t shifted = right_most_bit << power;
            ret +=shifted;
            n = n>>1;
            power -=1;
        }
        return ret;
    }
};



// 2^7  2^6  2^5 2^4  2^3  2^2  2^1  2^0   power..
//  1    0    1   0    1    0    1    0    original
//  0    1    0   1    0    1    0    1    reversed   