#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;
//brute force O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++){
            // since target = nums[i] + nums_wanted
            int num_wanted = target - nums[i]; 
            for (int j=i+1; j<n;j++){
                if(nums[j]==num_wanted)
                {
                    return {i, j};
                }
            }

        }
        return {};

    }
};

void run_solution()
{
    vector<int> vec_1 = {3,2,4};
    auto sol = Solution();

    auto output = sol.twoSum(vec_1, 6);
    std::cout << output[0] << " " << output[1] << std::endl;
}

//use hash map, O(n);
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIndex;
        int n = nums.size();

        for (int i =0; i<n;i++)
        {
            numToIndex[nums[i]]=i;
        }
        // Find the complement
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numToIndex.count(complement) && numToIndex[complement] != i) {
                return {i, numToIndex[complement]};
            }
        }

        return {}; // No solution found

    }
};

void run_solution2()
{
    vector<int> vec_1 = {3,2,4};
    auto sol = Solution2();

    auto output = sol.twoSum(vec_1, 6);
    std::cout << output[0] << " " << output[1] << std::endl;
}



int main()
{
    //run_solution();
    run_solution2();
}

//g++ -std=c++11 -o q1_two-sum q1_two-sum.cpp