#include<vector>
#include<unordered_map>

using std::vector;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // starting from 0, if we see "1" we add 1 and if we see "0" we minus 1. 
        // The regions that have the same total sum, means that the count of 0 and 1 are the same. 
        // we store in which index we see the "sum" first. Whenever, we come across the same "sum" value again 
        // later while traversing the array, we know that between these two regions, we have the same number of 0 and 1.  
        // so we need to find such regions furthest apart. 
        int sum =0;
        int max_length = 0;
        // store the index when we first see that value.
        std::unordered_map<int, int> index_first_see{{0, -1}}; 
        for (int i=0; i<nums.size(); i++) {
            sum += nums[i]==1 ? +1 : -1;
            if (index_first_see.count(sum)) {
                max_length = std::max(max_length, i - index_first_see[sum]);
            } else {
                index_first_see[sum] = i;
            }
        }
        return max_length;
    }
};