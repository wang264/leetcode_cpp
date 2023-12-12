#include <vector>

using std::vector;

class Solution {
public:
    int search(vector<int>& nums, int target) {
       if (nums.size()==1) {
           return nums[0]==target ? 0 : -1;
       }
       int left = 0;
       int right = nums.size()-1;

        // find the location of the split.
       while (left+1<right) {
           int mid = left + (right-left)/2;
           if (nums[mid]==target) {
               return mid;
           } else if (nums[mid]>nums[0]) {
               left = mid;
           } else {
               right = mid;
           }
       } 
       // find the pivot --> the minimum element;
       int pivot;
       if (nums[left]<nums[right]) {
           pivot = left;
       } else {
           pivot=right;
       }

       // binary search on two ranges.
       if (pivot==0) {
           return binary_search(nums, target, 0, nums.size()-1);
       } else {
           int rslt = binary_search(nums, target, 0, pivot-1);
           if (rslt==-1) {
               rslt = binary_search(nums, target, pivot, nums.size()-1);
           }
           return rslt;
       }
    }   
    int binary_search(vector<int>& nums, int target, int left, int right) {
        while(left+1<right) {
            int mid = left + (right-left)/2;
            if (nums[mid]==target) {
                return mid;
            } else if (nums[mid]<target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        if (nums[left]==target) {
            return left;
        } else if (nums[right]==target) {
            return right;
        } else {
            return -1;
        }
    }

};

//target = 5
// [4, 5, 6, 7, 0, 1, 2]
//left =     |        
//right=        |
//  0  1  2  3  4  5  6    


// nums= [3,1]   target=1

// nums= [1,3]   target =3

// nums = [0]    target =0

// nums = [1,3]   target=0