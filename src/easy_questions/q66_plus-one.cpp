#include <vector>

using std::vector;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> rslt;
        int carry = 1; //plus 1
        for(int i=digits.size()-1; i>=0; i--) {
            int temp = digits[i]+carry;
            if (temp==10) {
                carry=1;
                temp = 0;
            } else {
                carry=0;
            }
            rslt.push_back(temp);
        }
        if (carry) {
            rslt.push_back(1);
        }
        std::reverse(rslt.begin(), rslt.end());
        return rslt;
    }
};