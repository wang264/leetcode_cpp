#include<vector>
#include<unordered_set>

using std::vector;
using std::unordered_set;


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //Loop through the array, for each element do
        //  Search current element in the HashTable, return true if found
        //  Put current element in the HashTable
        //  If the size of the HashTable is larger than kkk, remove the oldest item.
        unordered_set<int> set;
        for (int i=0; i<nums.size(); i++) {
            if (set.count(nums[i])>0) {
                return true;
            }
            else{
                set.insert(nums[i]);
            }

            if (set.size()>k) {
                // remove the oldest element
                set.erase(nums[i-k]);
            }
        }
        return false;
    }
};