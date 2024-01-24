#include <vector>

using std::vector;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int left_min = prices[0];
        int right_max = prices[n-1];

        // left_profits[i]: the maximum profits that one can gain from doing one single transaction on the left subsequence of prices from prices[0] to prices[i]
        vector<int> left_profits(n, 0);

        // right_profits[i]: maximum profits that one can gain from doing one single transaction on the right subsequence of the prices from the index i up to N-1
        vector<int> right_profits(n,0);

        for (int i=1; i<n; i++) {
            // buy at day with price=left_min and sell at Day (i+1). 
            left_profits[i] = std::max(left_profits[i-1], prices[i]-left_min);
            left_min = std::min(left_min, prices[i]);
        }
        
        for (int i=n-2; i>=0; i--) {
            // buy at Day (i+1) and sell at the day with price=right_max;
            right_profits[i] = std::max(right_profits[i+1], right_max - prices[i]);
            right_max = std::max(right_max, prices[i]);
        }
        int max_profit = 0;
        for (int i=0; i<n; i++) {
            if (i==n-1) {
                max_profit = std::max(max_profit, left_profits[i]);
                continue;
            }
            max_profit = std::max(max_profit, left_profits[i] + right_profits[i+1]);
        }
        return max_profit;
    }
};