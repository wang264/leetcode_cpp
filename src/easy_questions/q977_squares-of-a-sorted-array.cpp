#include <vector>

using std::vector;

//O(n) solution with 2 pointers 
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        auto square = [] (int& num) { num=num*num;};
        std::for_each(nums.begin(), nums.end(), square);
        
        int left = 0;
        int right = nums.size()-1;
        
        vector<int> rslt = vector<int>(nums.size(),0);
        
        for (int i=nums.size()-1; i>=0; i--) {
            if (nums[left] < nums[right]) {
                rslt[i]=nums[right];
                right--;
            } else {
                rslt[i]=nums[left];
                left++;
            }
        }
        return rslt;
        
    }
};