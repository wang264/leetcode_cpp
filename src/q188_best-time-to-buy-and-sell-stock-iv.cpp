#include <limits.h>
#include <vector>

using std::vector;


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // dp[day_number][used_transaction_number][stock_holding_status] = balance
        // stock_holding_status is a 0/1 number representing whether you hold the stock or not.

        // The value of dp[i][j][l] represents the best profit we can have at the end of the i-th day, with j used transactions, and we have l stocks on hand at end of the i-th day.

        // j will increase when you buy, but will not increase when you sell. 

        // 4 status:
        // #1: Keep holding the stock:
        // dp[i][j][1]=dp[i−1][j][1]

        // #2: Keep not holding the stock:
        // dp[i][j][0]=dp[i−1][j][0]

        // #3: Buying, 
        // when j>0:
        // dp[i][j][1]=dp[i−1][j−1][0]−prices[i]

        // #4: Selling:
        // dp[i][j][0]=dp[i−1][j][1]+prices

    int n = prices.size();
    if (k==0 || prices.size()==0) {
        return 0;
    }
    if (k/2>n) {
        int rslt = 0;
        for (int i=1; i<n; i++) {
            rslt+= std::max(0, prices[i]-prices[i-1]);
        }
        return rslt;
    }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2, -1000000000)));

        dp[0][0][0] = 0;
        dp[0][1][1] = -prices[0];

        //fill the array
        for (int i=1; i<n; i++) {
            for (int j=0; j<=k; j++) {
                dp[i][j][0] = std::max(dp[i-1][j][0], dp[i-1][j][1]+prices[i]);
                if (j>0) {
                    // you can not hold stock without any transaction.
                    dp[i][j][1] = std::max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i]);
                }
            }
        }
        int rslt=0;
        for (int j=0; j<=k; j++) {
            rslt = std::max(rslt, dp[n-1][j][0]);
        }
        return rslt;

    }
};