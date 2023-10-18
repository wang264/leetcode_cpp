#include<vector>
#include<algorithm>

using std::vector;
using std::sort;

class Solution {
    
public:
    int hIndex(vector<int>& citations) {

    sort (citations.begin(), citations.end());

    int h_index = 0;
    int n = citations.size();
    for (int i = n-1; i>=0 ;i--)
    {
        if (citations[i]>h_index)
        {
            h_index ++;
        }
    }
    return h_index;


    }
};