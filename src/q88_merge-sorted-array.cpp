#include <vector>

using std::vector;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1; // end of nums1(non zero part)
        int j = n - 1; // end of nums2
        int k = m + n - 1;

        while (k >= 0){
            if (i >= 0 && j >= 0){
                if (nums1[i] > nums2[j]){
                    nums1[k] = nums1[i];
                    i--;
                }
                else{
                    nums1[k] = nums2[j];
                    j--;
                }
            }
            else if (j >= 0){
                nums1[k] = nums2[j];
                j--;
            }
            else{ // nums1 is already sorted, no ops}
            }
            
            k--;
        }
    }
};