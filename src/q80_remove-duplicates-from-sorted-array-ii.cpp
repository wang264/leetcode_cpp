#include <vector>

using std::vector;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() <= 2)
        {
            return nums.size();
        }
        //                  i
        // [0,0,1,1,2,3,3,3,3]
        //                j
        // count = 1
        // curr_num = 3

        int curr_num = nums[0]; // the current number
        int curr_count = 1;     // count of current number
        int j = 1;              // the place we overwrite number

        for (int i = 1; i < nums.size(); i++)
        { // if duplicate but count <2, then we need the i'th eleemnt so move the element from index i to index j
            if (curr_num == nums[i] && curr_count < 2)
            {
                curr_count++;
                nums[j] = nums[i];
                j++;
            }
            // don't need this so we dont move i'th element.
            else if (curr_num == nums[i] && curr_count >= 2)
            {
                curr_count++;
            }
            // a new element at hand and so accordingly, we update count = 1 and also move this element to index j
            else
            {
                nums[j] = nums[i];
                curr_num = nums[j];
                curr_count = 1;
                j++;
            }
        }
        return j;
    }
};