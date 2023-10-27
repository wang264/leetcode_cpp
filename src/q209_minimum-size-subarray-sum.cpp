#include<vector>
#include<math.h>
#include<limits.h>

using std::min;
using std::vector;

//https://github.com/wang264/JiuZhangLintcode/blob/master/AlgorithmAdvance/L1/require/406_minimum-size-subarray-sum.py

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    // two pointer algorithm.
    // start from left=0, and right=0 and keep increasing right, and calculate the sum. 
    // whenever sum(nums[0] ....nums[right]])>target, we know that for the subarray that ends
    // at index right, the shortest would from "left to "right", we store its length and update 
    // right_new= right+1, for the new "right" position, we move "left" pointer to the right
    //  left_new=left+?? to find the shortest path such that  
    // sum(nums[left_new] ....nums[right_new]])>target... for each right_new, we dont need to consider
    // the case for left pointer < "left" becasue we already know that sum(nums[left]...nums[right_new]) > target
    // so move "left" pointer to the left will only make the sum bigger and longer.
    // 同向双指针
    // 每次删除左指针左边的数字。
    // 只要当前和小于S, 右指针继续向右移动
    // 时间复杂度O(N)

        int n = nums.size();
        int ans = INT_MAX;
        int sum = 0;
        int left=0;
        for (int right=0; right<n; right++) {
            sum +=nums[right];
            // we have one solution
            while (sum>=target) {
                // try to find the shortest solution when fix 'right'
                ans = min(ans, right-left+1);
                sum-=nums[left];
                left++;
            }
        }
        return (ans!=INT_MAX) ? ans : 0;    
    }
};


int main()
{
    return 0;
}

// g++ -std=c++11 -o q209_minimum-size-subarray-sum q209_minimum-size-subarray-sum.cpp
