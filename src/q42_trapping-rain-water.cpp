#include<vector>
#include<math.h>

using std::vector;

class Solution {
public:
    int trap(vector<int>& height) {
    
    int n = height.size();
    
    // the running max from the left.
    vector<int> L = vector<int>(n);
    // the running max from the right.
    vector<int> R = vector<int>(n);

    //for ith cell, the rain water it can trap is min(L[i], R[i]) - height[i]
    L[0] = height[0];
    for (int i = 1; i<n; i++){
        if(height[i] > L[i-1]){
            L[i] = height[i];
        }
        else {
            L[i] = L[i-1];
        }
    }

    R[n-1] = height[n-1];
    for(int i = n-2; i>=0; i--){
        if(height[i]>R[i+1]){
            R[i] = height[i];
        }
        else{
            R[i] = R[i+1];
        }
    }
    int sum = 0;
    for (int i=0; i<n; i++){
        sum += std::min(L[i], R[i]) - height[i];
    }
    return sum;
    }
};