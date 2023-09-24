#include <vector>
#include <unordered_map>

using std::unordered_map;
using std::vector;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> num_to_count;
        for (int i = 0; i < nums.size(); i++)
        {
            num_to_count[nums[i]]++;
        }
        // majority count threshold
        int m = nums.size() / 2;
        for (auto x : num_to_count)
        {
            if (x.second > m)
            {
                return x.first;
            }
        }
        return 0;
    }
};