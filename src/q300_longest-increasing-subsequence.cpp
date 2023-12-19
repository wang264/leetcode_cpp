#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        // dp[i]: the longest increasing subsequence from nums[0] to nums[i]
        for( int i=1; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (nums[i]>nums[j]) {
                    dp[i] = std::max(dp[i], dp[j]+1);
                }
            }
        }
        return *std::max_element(dp.begin(), dp.end());
    }
};