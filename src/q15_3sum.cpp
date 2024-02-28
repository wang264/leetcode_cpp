#include<vector>

using std::vector;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> rslt;
        //we use index to track the index of the first element. 
        // short circuit when nums[i]>0 because after sorted, other numbers from the right would only be bigger, can not sum to zero
        for (int i=0; i<=nums.size()-3 && nums[i] <= 0; i++) {
            if (i>0 && nums[i-1]==nums[i]) { //do not over count the answer, need to be distinct.
                continue; 
            }
            //the rest is two sum sorted array;
            int target = 0 - nums[i];
            int left = i + 1;
            int right = nums.size() - 1;

            while (left<right) {
                if (nums[left] + nums[right] < target) {
                    left++;
                }
                else if (nums[left] + nums[right] > target) {
                    right--;
                }
                else {
                    // found one of the answer
                    vector<int> oneAnswer = {nums[i], nums[left], nums[right]};
                    rslt.push_back(oneAnswer);
                    left++;
                    right--;
                    // since we can not have the same triplet, need to find a different left number.
                    while (left<right && nums[left] == nums[left-1]) {
                        left++;
                    }
                }
            }
        }

        return rslt;
    }
};