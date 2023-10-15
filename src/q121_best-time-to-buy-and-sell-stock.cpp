#include<vector>

using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int running_min = 99999;

        for (const auto& p : prices)
        {
            if (p < running_min)
            {
                running_min = p;
            }

            int profit_if_sell_today = p - running_min;
            if (profit_if_sell_today > max_profit)
            {
                max_profit = profit_if_sell_today;
            }
        }

        return max_profit;
    }
};