#include <vector>
using std::vector;

 
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        // dp[i]: the fewest number of coins that you need to make up amount "i", -1 means there is no such way to make up that amount.
        dp[0]=0; // 0 coin to make up amount 0;
        for (int i=1; i<=amount; i++) {
            for (const int coin: coins) {
                int residual = i - coin;
                if (residual>=0 && dp[residual]>=0) {
                    int num_coin = dp[residual]+1;
                    if (dp[i]==-1) { // mean we have not yet found a valid way yet.
                        dp[i]=num_coin;
                    } else {
                        dp[i] = std::min(dp[i], num_coin);
                    }
                }
            }
        } 
        return dp[amount];
    }
};