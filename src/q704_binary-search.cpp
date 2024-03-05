
#include <vector>
using std::vector;



class Solution1 {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left<=right) {
            int mid = left+(right-left)/2;
            if (nums[mid] > target) {
                right = mid-1;
            } else if (nums[mid]<target) {
                left = mid+1;
            } else {return mid;}
        }
        return -1;
    }
};

class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;

        while(left+1<right) {
            int mid = left+(right-left)/2;
            if (nums[mid] > target) {
                right = mid-1;
            } else if (nums[mid]<target) {
                left = mid+1;
            } else {return mid;}
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