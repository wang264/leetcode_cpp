#include <vector>
#include <unordered_map>

using std::vector;

// at index "i", "sum"= nums[0]+nums[1]+...nums[i]   "sum" is the prefix sum.
// as we iterate array from left to right, we use a hash map with (key, value)=("sum", frequency of sum occour)

// for a index i, we know the "sum_i"= nums[0]+...sum[i]=X. and if dictionary contains the 
// key (X-k), we know that at some index "j" such that j<i, we have sum_j = nums[0]...nums[j] = X -k
// sum_i= nums[0]+..+nums[j]+....sum[i] = X   (1)
// sum_j = nums[0]...nums[j] = X -k           (2)
// (1) - (2) yield  nums[j+1] + nums[j+2]..+..nums[i] = k
// so we find at least one sub array with its sum equals k, there could be more than 1, 
// so we use hash map to store the how many time a sub array's sum equals to X-k had occour. 
// (1) will the arry from nums[0]..ending at nums[i], and (2) is that subarrays we find in the hashmap.
// (1) -(2) is the answer.

class Solution1 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0; 
        int sum = 0;
        std::unordered_map<int,int> map = {{0,1}};
        for (int i=0; i<nums.size(); i++) {
            sum += nums[i];
            if (map.count(sum-k)) {
                int temp = map[sum-k];
                count +=temp;
            }
            map[sum]++;


        }
        return count;
    }
};

// prefix_sum[0] = 0
// prefix_sum[i] = nums[0] + nums[1] + ... + nums[i-1]   sum of first i elements, end at index (i-1).
// prefix_sum[k] = nums[0] + nums[1] + ... + nums[i-1]...+ nums[k-1]    sum of first k elements. end at index (k-1).
// prefix_sum[k] - prefix_sum[i] =    nums[i] + ......+ nums[k-1];


// thus, nums[i] + ....nums[j] =  prefix_sum[j+1] - prefix_sum[i]

// [1,2,3]
//0,1,3,6


class Solution2 {  // use O(n) space.
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        std::vector<int> prefix_sum = std::vector(nums.size()+1, 1);
        prefix_sum[0]=0;
        for (int i=0; i<nums.size(); i++) {
            prefix_sum[1+i] = prefix_sum[i]+nums[i];
        }

        for (int start = 0; start<nums.size(); start++) {
            for (int end = start; end<nums.size(); end++) {
                if (prefix_sum[end+1]-prefix_sum[start] == k) {
                    count++;
                }
            }
        }
        return count;


    }
};


// choose a particular 'start' point and while iterating over the 'end' points, 
// we can add the element corresponding to the endendend point to the sum formed till now. 
// Whenever the "sum" equals the required k value, we can update the "count" value. 

class Solution3 {    //no extra space.
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for (int start=0; start<nums.size(); i++) {
            int sum = 0;
            for (int end = start; end<nums.size(); i++) {
                sum+=nums[end];
                if (sum == k) {
                    count++;
                }
            }
        }
        return count;
    }
};
