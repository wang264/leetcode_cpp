#include <vector>

using std::vector;

class Solution {
public:
    int climbStairs(int n) {
       if (n==1) {
           return 1;
       }
       
       std::vector<int> dp = {1, 2};
       for (int i=2; i<n; i++) {
           dp[i%2] = dp[(i-1)%2] + dp[(i-2)%2];
       }
       return dp[(n-1)%2];
    }
};