#include <vector>
#include <utility>      // std::pair, std::make_pair

using std::vector;
using std::pair;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //we mark the visited will a special number 999
        int VISITED = 101;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int row = 0;
        int col = 0;
        // four direction we will move: right, down, left, up. 
        vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int curr_direction = 0;
        int change_direction = 0; // store the number of times we change direction

        vector<int> rslt = {matrix[0][0]};
        matrix[0][0] = VISITED;

        while (change_direction<2) {
            while (true) {
                // calculate the next palce
                int next_row = row + directions[curr_direction].first;
                int next_col = col + directions[curr_direction].second;
                
                // break if out of bound
                if (next_row<0 || next_row >=rows || next_col<0 || next_col>=cols) {break;}
                // break if next step is visited
                if (matrix[next_row][next_col]==VISITED) {break;}
                // reset change_direction
                change_direction = 0;
                // update current position
                row = next_row;
                col = next_col;
                rslt.push_back(matrix[row][col]);
                matrix[row][col] = VISITED;
            }
            // change our direction
            curr_direction=(curr_direction+1) % 4;
            // increse change direction
            change_direction++;
        }
        return rslt;

        
    }
};