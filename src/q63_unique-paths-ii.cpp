#include <vector>
using std::vector;


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n_rows = obstacleGrid.size();
        int n_cols = obstacleGrid[0].size();

        vector<vector<int>> dp(n_rows, vector<int>(n_cols, 0));
        //dp[i][j], number of ways robot to reach to grid[i][j]
        
        //first row
        for (int j=0; j<n_cols; j++) {
            if (obstacleGrid[0][j]==0) { // no obstacle
                dp[0][j] = 1;
            } else {
                break;
            }
        }

        // first column
        for (int i=0; i<n_rows; i++) {
            if (obstacleGrid[i][0]==0) {
                dp[i][0] = 1;
            } else {
                break;
            }
        }

        for (int i=1; i<n_rows; i++) {
            for (int j=1; j<n_cols; j++) {
                if (obstacleGrid[i][j]==1) {
                    dp[i][j]=0;
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[n_rows-1][n_cols-1];
    }
};