#include <vector>

using std::vector;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return nums.size();
        }
        int curr_num = nums[0]; // to store the current number
        int j = 1;              // if duplicate, then replace the number in this index.

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != curr_num)
            {
                // we see a different number, in this case, we assign the different number to nums[j], update the current number, and move j to the next position.
                nums[j] = nums[i];
                curr_num = nums[j];
                j++;
            }
            // if nums[i] == curr_num, means that we see a duplicate, we continue to check the next number.
        }
        return j;
    }
};