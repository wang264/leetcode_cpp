#include <vector>
#include <queue>
#include <algorithm>

using std::vector;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, vector<int>, std::greater<int>> pq;  // we need a min queue 
        for (const auto& num: nums) {
            pq.push(num);
            if (pq.size()>k) {
                pq.pop();
            }
        }
        return pq.top();
        
    }
};