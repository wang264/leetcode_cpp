#include <vector>

using std::vector;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size()==0) {
            return {-1,-1};
        }
        int left = 0;
        int right = nums.size()-1;

        while (left+1<right) {
            int mid = left + (right-left)/2;
            if (nums[mid]==target) {
                left = mid; //continue to find the last occourance.
            } else if (nums[mid]<target) {
                left=mid;
            } else {
                right=mid;
            }
        }
        if (nums[left]!=target && nums[right]!=target) {
            return vector<int>(2,-1);
        } else {
            int right_most = nums[right]==target ? right : left;
            int left_most = right_most;
            while(left_most>=0 && nums[left_most]==target) {
                left_most--;
            }
            return {left_most+1, right_most};
        }

    }
};

// [5, 7, 8 ,8, 10]  
//           |    
//               |
//  0  1  2  3   4


// nums=[1], target=1
// nums=[2,2], target=2