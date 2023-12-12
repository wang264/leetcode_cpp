#include <vector>

using std::vector;


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = nums.size()-1;

        while (left+1<right) {
            int mid = left + (right-left)/2;
            if (nums[mid-1]<nums[mid]) {
                left=mid;
            } else if (nums[mid-1]>nums[mid]) {
                right = mid;
            } else {
                continue;
            }
        }

        if (nums[left]>nums[right]) {
            return left;
        } else {
            return right;
        }

    }
};