#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        // dp[i] = the sum of maximum subarray ending at nums[i]
        dp[0] = nums[0];
        for (int i=1; i<n; i++) {
            // if the sum of maximum subarray ending at nums[i-1] is smaller than zero, 
            // then we dont want to use those numbers since it will make the sum including
            //  nums[i] smaller. we would rather start fresh.
            if (dp[i-1]<0) {
                dp[i] = nums[i];
            } else {
                // we want to include this number, it will make the sum larger.
                dp[i] = dp[i-1] + nums[i];
            }
        }
        return *std::max_element(dp.begin(), dp.end());
    }
};

// 1. Initialize 2 integer variables. Set both of them equal to the first value in the array.

//    - currentSubarray will keep the running count of the current subarray we are focusing on.
//    - maxSubarray will be our final return value. Continuously update it whenever we find a bigger subarray.

// 2. Iterate through the array, starting with the 2nd element (as we used the first element to initialize our variables). For each number, add it to the currentSubarray we are building. If currentSubarray becomes negative, we know it isn't worth keeping, so throw it away. Remember to update maxSubarray every time we find a new maximum.

// 3. Return maxSubarray.

class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        int current_subarray = nums[0];
        int max_subarray = nums[0];

        for (int i=1; i<nums.size(); i++) {
            // If current_subarray is negative, throw it away. Otherwise, keep adding to it.
            if (current_subarray<0) {
                current_subarray = nums[i];
            } else {
                current_subarray = current_subarray+nums[i];
            }
            max_subarray = std::max(max_subarray, current_subarray);
        }
        return max_subarray;
    }
};
