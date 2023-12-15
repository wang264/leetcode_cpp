#include <vector>
using std::vector;

// If we take XOR of zero and some bit, it will return that bit
// If we take XOR of two same bits, it will return 0
// So we can XOR all bits together to find the unique number.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for (const auto& num: nums) {
            result^=num;
        }
        return result;
    }
};