#include<limits>
#include<algorithm>
#include <vector>


using std::vector;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int best_diff = INT_MAX;
        // two pointer, fix the first number. 
        for (int i=0; i<=nums.size()-3; i++) {
            int low = i+1;
            int high = nums.size()-1;
            while(low<high && best_diff!=0) {
                int sum = nums[i] + nums[low] + nums[high];
                if (std::abs(sum - target) < std::abs(best_diff)) {
                    best_diff = sum - target; //update if we get closer.
                }
                if (sum>target) {
                    high--;
                } else {
                    low++;
                }
            }
            
        }

        return best_diff + target;

    }
};
