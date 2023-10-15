#include<limits>
#include<vector>
#include<algorithm>

using std::vector;
using std::min;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp = vector<int>(n, INT_MAX);
        // dp[i] = minimum jumps to reach position at index i;
        dp[0] = 0; // you start from index 0

        for (int i = 0; i<n; i++)
        {
            for (int j = 1; j<=nums[i]; j++)
            {
                int k = i+j; // jump j step from position i --> to index k
                if (k <= n-1){  // jump is valid
                    // dp[k] store the minmum jump to index k, if you start at index i and jump 
                    // 1 step to dp[k], and that number is smaller than dp[k], means you can find
                    // a better way to get jump there. 
                    dp[k] = min( dp[k], dp[i]+1);
                }
            }
        }
        return dp[n-1];

    }
};