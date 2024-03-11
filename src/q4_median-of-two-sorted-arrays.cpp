#include <vector>
using std::vector;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size_1 = nums1.size();
        int size_2 = nums2.size();
        int n = size_1 + size_2;

        // if n is odd, this is the index for median.
        // if n is even, this index is bias towards the right. need to average with the number to its left.
        if (n % 2 == 0) {
            return (findKth(nums1, nums2, n/2) + findKth(nums1, nums2, n/2+1))/2.0;
        } else {
            return findKth(nums1, nums2, n/2+1);
        }
    }

    int findKth(vector<int>& A, vector<int>& B, int k) {
        if (A.size()==0) {
            return B[k-1];
        }
        if (B.size()==0) {
            return A[k-1];
        }
        // possible median
        int start = std::min(A[0], B[0]);
        int end = std::max(A.back(), B.back());

        while (start+1<end) {
            int mid = start + (end-start)/2;
            // if together there are less than k element smaller than the perpose median,
            // then the true median must larger or equal to the perpose median
            if (countSmallerOrEqual(A, mid) + countSmallerOrEqual(B, mid) < k) {
                start = mid; 
            } else {
                // for thr equal case, if there are exactly k number smaller or equal, the k th largest could be a smaller number
                end = mid;
            }
        }
        if (countSmallerOrEqual(A, start) + countSmallerOrEqual(B, start)>=k) {
            return start;
        } else {
            return end;
        }
    }

    int countSmallerOrEqual(vector<int>& A, int target) {
        // we want to find the position such that in that index, 
        // it is larger than target, and the numbers to its left are
        // smaller or equal to target. So, that index will be the number of 
        // elements in the array that smaller or equal to target.
        int left = 0;
        int right = A.size()-1;
        if (target<A[left]) {return 0;}
        if (target>=A[right]) {return right+1;}

        while (left+1<right) {
            int mid = left + (right-left)/2;
            if (A[mid]<=target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        if (A[left]>target) {
            return left;
        }
        if (A[right]>target) {
            return right;
        }
        return -1;
    }
};