#include <vector>

using std::vector;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //input matrix m x n could be considered as a sorted array of length m x n.
        int n_rows = matrix.size();
        int n_cols = matrix[0].size();
        int left = 0;
        int right = n_rows*n_cols-1;

        while (left<=right) {
            int mid = left + (right-left)/2;
            int i = mid / n_cols;
            int j = mid % n_cols;
            int mid_element = matrix[i][j];
            if (mid_element==target) {
                return true;
            } else if (target<mid_element) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
};


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //first binary seach to find the rows.
        int n_rows = matrix.size();
        int n_cols = matrix[0].size();
        int up = 0;
        int down = n_rows-1;
        while (up<=down) {
            int mid = up + (down - up)/2;
            int mid_val = matrix[mid][n_cols-1]; // the last element of each row
            if (mid_val == target) {
                return true;
            } else if (mid_val < target) {
                up = mid+1;
            } else {
                down = mid-1;
            }
        }
        int row = up;
        
        if (row>=n_rows) {
            // special case, consider matrix = [[1]], target=2, 
            // then row will be equalt to 1 instead of zero. 
            row = n_rows-1;
        }

        //then use second binary search to find the correct column
        int left = 0;
        int right = n_cols -1;
        while (left<=right) {
            int mid = left + (right-left)/2;
            int mid_val = matrix[row][mid];
            if (mid_val == target) {
                return true;
            } else if (mid_val < target) {
                left = mid+1;
            } else {
                right = mid -1;
            }
        }
        return false;
    }


};