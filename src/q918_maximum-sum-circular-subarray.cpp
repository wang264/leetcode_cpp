#include <vector>

using std::vector;


class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightMax(n);
        rightMax[n-1] = nums[n-1];
        int suffixSum = nums[n-1];
        
        for (int i =n-2; i>=0; i--) {
            suffixSum+= nums[i];
            rightMax[i] = std::max(rightMax[i+1], suffixSum);
        }

        int maxSum = nums[0];
        int specialSum = nums[0];
        int curMax = 0;
        int prefixSum=0;
        for (int i=0; i<n; i++) {
            //Kadane's algorithm
            curMax = std::max(curMax, 0) + nums[i];
            maxSum = std::max(maxSum, curMax);

            prefixSum += nums[i];
            if (i+1<n) {
                specialSum = std::max(specialSum, prefixSum + rightMax[i+1]);
            }
        }
        return std::max(maxSum, specialSum);
    }
};