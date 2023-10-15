#include <vector>

using std::vector;

// [1, 7, 2, 3, 6, 7, 6, 7]
// for unlimit transaction the best option is to do the following, for each day i and i+1, 
//if Prices[i] < Price[i+1] we buy at ith day and sell at (i+1)th day. other wise we do nothing. 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        for (int i=0; i<prices.size()-1; i++)
        {
            if (prices[i]<prices[i+1])
            {
                // we buy at ith day and sell at (i+1)th day. 
                max_profit += prices[i+1] - prices[i];
            }
        }
        return max_profit;
    }
};