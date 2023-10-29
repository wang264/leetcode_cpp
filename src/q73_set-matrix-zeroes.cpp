#include<vector>

using std::vector;


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // space complexity O(m +n) 
        int n = matrix.size();
        int m = matrix[0].size();
        vector<bool> rows(n, false);
        vector<bool> cols(m, false);

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (matrix[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (rows[i] || cols[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

class Solution2 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // space complexity O(1) 
        int n = matrix.size();
        int m = matrix[0].size();
        //Rather than using additional variables to keep track of rows and columns 
        // to be reset, we use the matrix itself as the indicators.

        // Since first cell for both first row and first column is the same i.e. matrix[0][0]
        // We can use an additional variable for either the first row/column.
        // For this solution we are using an additional variable for the first column
        // and using matrix[0][0] for the first row.
        bool isCol = false;

        for (int i=0; i<n; i++) {
            if (matrix[i][0] == 0) {
                isCol = true;
            }

            for (int j=1; j<m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Iterate over the array once again and using the first row and first column, update the elements.
        for (int i=1; i<n; i++) {
            for (int j=1; j<m; j++) {
                if (matrix[i][0]==0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        // See if the first row needs to be set to zero as well
        if (matrix[0][0] == 0) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        // See if the first column needs to be set to zero as well
        if (isCol) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }

    }
};