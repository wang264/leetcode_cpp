#include <vector>

using std::vector;

// So, concluding, to compute the ith bit of the loner, we can add the ith
// bit of all integers and take modulo 3. This will give us the ith
// bit of the loner. We will do this for every bit, and thus, we will get the loner.

// A XOR B = (A+B) mod 2

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // loner
        int loner=0;
        int mask = 1;

        // Iterate over all bits
        for (int shift=0; shift<32; shift++) {
            int bitSum=0;

            // For this bit, iterate over all integers
            for (auto& num: nums) {
                // Compute the bit of num, and add it to bitSum
                bitSum += (num >> shift) & 1;
            }
            
            // Compute the bit of loner and place it
            int lonerBit = bitSum % 3;
            loner = loner | (lonerBit<<shift);
        }
        return loner;
    }
};