#include<vector>
#include<algorithm>

using std::vector;
using std::max;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        // dp[i]=true; you can jump to this location from starting position
        // dp[i]=false; you can not jump to this location from starting position
        int n = nums.size();
        vector<bool> dp = vector<bool>(n, false);
        
        dp[0] = true; // you start from here. 
        for (int i=0; i<n; i++)
        {
            if (dp[i]){
                // j is the step we jump from dp[j]
                for (int j=1; j<=nums[i];j++)
                {
                    int k = i+j;
                    if (k <= n-1){
                        dp[k] = true; // we can jump to dp[i+j]
                    }
                }
            }
        }
        return dp[n-1];
    }
};

class Solution2 {
// For each element, it checks if the current index i is greater than maxReach. If it is, 
// then it means that it is not possible to reach the current index from any of the previous 
// indices, so the function returns false. Otherwise, it updates maxReach to be the maximum of 
// its current value and i + nums[i], which represents the maximum index that can be reached 
// from the current index.

// After iterating over all elements, if no false value has been returned, then it means that it is 
// possible to reach the last index, so the function returns true.

public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0;

        for (int i =0; i<n; i++)
        {
            if(i > maxReach){
                return false;
            }
            maxReach = max(maxReach, i + nums[i]);
        }

        return true;
        
    }
};
