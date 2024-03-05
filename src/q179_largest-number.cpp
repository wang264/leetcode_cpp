#include <string>
#include <vector>

using std::vector;
using std::string;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto compare = [] (int a, int b){
            string s_ab= std::to_string(a)+std::to_string(b);
            string s_ba= std::to_string(b)+std::to_string(a);
            return s_ab>s_ba;
        };
        std::sort(nums.begin(), nums.end(), compare);
        if (nums[0]==0) {
            return "0";
        }
        string rslt;
        for(const int num:nums) {
            rslt+=std::to_string(num);
        }
        return rslt;
    }
};