#include <vector>


using std::vector;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        //This problem is known as Dutch National Flag Problem and first was proposed by
        // Edsger W Dijkstra. 

        int left = 0;
        int right = nums.size()-1;
        int curr = 0;
        // we iterate the numbers, whenever we see a 0, we swap it with nums[left], and left++
        // whenever we see a 2, we swap it with nums[right], and right--
        // left: point to the location of zero, the location that is left of "left pointer" must be zero.
        // right: point to the location of two, the location that is right of "right pointer" must be two.
        while(curr<=right) {
            if (nums[curr]==0) {
                std::swap(nums[curr], nums[left]);
                left++;
                curr++;
            } else if (nums[curr]==2) {
                std::swap(nums[curr], nums[right]);
                right--;
            } else {
                curr++;
            }
        }
        
        
    }
};