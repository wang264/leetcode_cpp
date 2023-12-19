#include <vector>
using std::vector;


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n_rows = grid.size();
        int n_cols = grid[0].size();
        // first row.
        for (int j = 1; j<n_cols; j++) {
            grid[0][j]+=grid[0][j-1]; 
        }
        // first column 
        for (int i=1; i<n_rows; i++) {
            grid[i][0] += grid[i-1][0];
        }
        for (int i=1; i<n_rows; i++) {
            for (int j=1; j<n_cols; j++) {
                int min_prev = std::min(grid[i-1][j], grid[i][j-1]);
                grid[i][j] += min_prev;
            }
        }


        return grid[n_rows-1][n_cols-1];
    }
};