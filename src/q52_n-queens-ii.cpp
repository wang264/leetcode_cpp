#include <vector>

using std::vector;


class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> cols(n, false); // if cols[i]=true, means there is a queen in the ith column.
        vector<bool> diagonal(2*n-1, false); // if diagonal[4]=true, means there must be a queen in one of (4,0), (3,1), (2,2), (1,3), (0, 4)
        vector<bool> anti_diagonal(2*n-1, false);
        int count=0;
        dfs(0, n, cols, diagonal, anti_diagonal, count);
        return count;

    }
    bool isValid(int n, int row, int col, vector<bool>& cols, 
                 vector<bool>& diagonal, vector<bool>& anti_diagonal) {
         // check if we can put another queen here. 
        if (cols[col] || diagonal[row+col] || anti_diagonal[row - col + n]) {
            return false;
        } else {
            return true;
        }

    }
    void dfs(int curr_row, int n, vector<bool>& cols, 
            vector<bool>& diagonal, vector<bool>& anti_diagonal, int& count) {
        for (int col=0; col<n; col++) { 
            //try differeent column to see if we can put a queen in the current row.
            if(isValid(n, curr_row, col, cols, diagonal, anti_diagonal)) {
                // see we have enought queen
                if (curr_row == n-1) {
                    count++;
                    return;
                }

                //put queen
                cols[col] = true; //trun means there is a queen in there
                diagonal[curr_row+col] = true;
                anti_diagonal[curr_row-col+n] = true;
                dfs(curr_row+1, n, cols, diagonal, anti_diagonal, count);
                //remove queen
                anti_diagonal[curr_row-col+n] = false;
                diagonal[curr_row+col] = false;
                cols[col] = false;

            } 
        }
    }
};