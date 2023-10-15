#include <vector>
#include <iostream>
#include <algorithm>  // std::reverse

using std::vector;

// Time limit Exceed
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int steps = k % nums.size();
        for (int i = 0; i < steps; i++)
        {
            // O(1) operation
            int value = nums.back();
            // O(1) operation
            nums.pop_back();
            // O(n) operation each, reallt in efficient
            nums.insert(nums.begin(), value);
        }
        
    }
};

class Solution2 {
//This approach is based on the fact that when we rotate the array k times, 
//k elements from the back end of the array come to the front and the 
// rest of the elements from the front shift backwards.

public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        
        // Example:-1234567 ,k=3, n = 7 
        // 1.first reverse the numbers form index 0 to n-k;
        // ->4321 567
        // 2.reverse the k elements from the last
        // ->4321 765
        // 3.now reverse the whole nums;
        // ->5671234 Done Answer is here !!!!
        std::reverse(nums.begin(),nums.begin()+(nums.size()-k));

        std::reverse(nums.begin()+(nums.size()-k),nums.end());
    
        std::reverse(nums.begin(),nums.end());
        
        
    }
};


class Solution3 {
// use an extra array in which we place every element of the array at its correct location.
// for exmaple, the number at index i in the original array is placed at the 
// index (i+k) % nums.size(), Then we copy the new array to the original one.
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int>* new_nums_ptr = new std::vector<int>(n, 0);
        vector<int>& new_nums = * new_nums_ptr;
        // vector<int> new_nums(n, 0);

       for (int i = 0; i<n; i++)
       {
           new_nums[(i+k) % n] = nums[i];
       }


       nums = new_nums;
    }
};

void run_solution3()
{
    vector<int> v = {1,2,3,4,5,6,7};
    auto sol3 = Solution3();
    sol3.rotate(v, 3);
    for (const auto i: v)
        std::cout << i << ' ';
    std::cout << std::endl;

}
int main(){
    // run_solution();
    run_solution3();
}

// g++ -std=c++11 q_189_rotate-array.cpp -o q_189_rotate-array.tsk



