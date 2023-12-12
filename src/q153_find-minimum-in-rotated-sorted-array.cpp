#include <vector>
using std::vector;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        
        // no rotation.
        if (nums[right]>nums[left]) {
            return nums[0];
        }
        while (left+1<right) {
            int mid = left + (right-left)/2;
            if (nums[mid]<nums[n-1]) {
                right=mid;
            } else if (nums[mid]>nums[n-1]) {
                left=mid;
            } else {
                right=mid;
            }
        }
        return std::min(nums[left], nums[right]);
    }
};