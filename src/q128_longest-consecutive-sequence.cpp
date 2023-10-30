#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    // store all numbers in the hash set
    // iterate the hashset, for each number such that number-1 is not in the set.
    // (begin of a consecutive series, we find the whole series)
    if (nums.size()==0) {
        return 0;
    }
    unordered_set<int> set;
    for (const auto& i: nums) {
        set.insert(i);
    }
    int longest = 1;
    for (const auto& i: set) {
        if (set.count(i-1)==0) {
            int curr_num = i;
            int count = 1;

            while(set.count(curr_num+1)>0) {
                curr_num++;
                count++;
                longest = count>longest ? count : longest;
            }
        }
    }

    return longest;
    }
};