#include<vector>
#include<utility> // std:pair


using std::vector;
using std::pair;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

    // need to encode current state and next state. 
    // -1 means, now is live(1) and next stage will be dead(negative sign)
    // 2 means,  now is dead(0) and next stage will be live(positive sign);

    vector<pair<int,int>> neighbors = {{1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1}};

    int rows = board.size();
    int cols = board[0].size();
    

    // iterate the cells
    for (int row=0; row<rows; row++) {
        for (int col=0; col<cols; col++) {
            // for each cell count the number of live neighbors
            int live_neighbors = 0;
            for (const auto& neighbor: neighbors) {
                int r = row + neighbor.first;
                int c = col + neighbor.second;

                // check if (r,c) is valid, 
                if (r<rows && r>=0 && c<cols && c>=0 && abs(board[r][c])==1) {
                    live_neighbors++;
                }
            }

            // rule 1 or rule 3
            if (board[row][col]==1 && (live_neighbors<2 || live_neighbors>3)) {
                board[row][col] = -1;
            }
            //rule 4
            if (board[row][col]==0 && live_neighbors==3) {
                board[row][col] = 2;
            }
        }
    }
    //get the final representation for the newly updated board;
    for (int row=0; row<rows; row++) {
        for (int col=0; col<cols; col++) {
            if (board[row][col]>0) {
                board[row][col] =1;
            }
            else {
                board[row][col] =0;
            }
        }
    }
    }
};