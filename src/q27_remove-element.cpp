#include<vector>
using std::vector;


class Solution{
public:
    int removeElement(vector<int> &nums, int val){
        int i = 0;
        int j = nums.size() - 1;
        while (i <= j){
            if (nums[i] == val){
                // swap the current element out and dispose the last one.
                nums[i] = nums[j];
                j--;
            }
            else{
                i++;
            }
        }
        // j will be the index of the last number we wanted. so return j+1
        return j + 1;
    }
};