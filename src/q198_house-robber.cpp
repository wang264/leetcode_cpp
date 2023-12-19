#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n<=2) {
            return *std::max_element(nums.begin(), nums.end());
        }
        vector<int> dp(n+1, 0);

    
        // dp[n]:  the maximum possible income for robbing first N house. 
        dp[0] = 0;  // maximum profit to rob no houses are zero.
        dp[1] = nums[0];
        for (int i=2; i<=n; i++) {
            // dp[i-1]: if we do not rob the ith house, the profit would be same as the maxium profit of robing first (i-1) house
            // dp[i-2] + nums[i-1]: if we DO rob the ith house, the profit would be the profit from robing the ith house(nums[i-1]), and the profit from robbing the first (i-2) houses. 
            dp[i] = std::max(dp[i-1], dp[i-2]+nums[i-1]);
        }
        return dp[n];
    }
};