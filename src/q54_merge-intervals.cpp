#include <vector>
#include <math.h>


using std::vector;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;

        for (const auto& interval: intervals) {
            //if the list is empty OR if the current interval does not overlap with the previous. 
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            }
            // otherwise, there is overlap, so we merge the current and previous interval.
            else {
                merged.back()[1] = std::max(merged.back()[1], interval[1]);
            }
        }
    return merged;   
    }
};



