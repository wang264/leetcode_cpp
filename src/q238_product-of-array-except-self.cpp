#include<vector>

using std::vector;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // L[i] = nums[0]*nums[1]....nums[i-1]
        // L[0] = 1
        vector<int> L = vector<int>(n,1);
        // R[i] = nums[n-1]*nums[n-2]....nums[i+1]
        // R[n-1] = 1
        vector<int> R = vector<int>(n,1);

        for (int i = 1; i<n; i++)
        {
            L[i]=L[i-1]*nums[i-1];
        }

        for (int i = n-2; i>=0; i--)
        {
            R[i] = R[i+1]*nums[i+1];
        }

        vector<int> answer;
        for (int i =0; i<n; i++)
        {
            answer.push_back(L[i]*R[i]);
        }
        return answer;
    }
};

class Solution2 {
// this approach is similar to the previous approach, but the difference is that
// we construct R array on the fly from right to left. 
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // L[i] = nums[0]*nums[1]....nums[i-1]
        // L[0] = 1
        vector<int> L = vector<int>(n,1);

        for (int i = 1; i<n; i++)
        {
            L[i]=L[i-1]*nums[i-1];
        }

        // R[i] = R[i+1]*nums[i+1];
        // we use an int instead an array;
        int R = 1;

        for (int i = n-1; i>=0; i--)
        {   
            L[i] = L[i]*R;
            R = R * nums[i];
        }
        return L;
    }
};