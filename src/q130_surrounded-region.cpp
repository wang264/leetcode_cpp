#include <queue>
#include <vector>

using std::vector;

//start from the edges, mark the cell that can ESCAPE, "O" on the edge and other O that are connected.  
// after we visit all the edges, the existing O will be mark to X and existing ESCAPE will be mark to O.
//bfs version
class Solution {
// this solution use bfs.
// in the bfs_helper() we visit all the neighbors of the boarder cells and change 
// the 'O' we see to 'E' means that cell can be escape.

// after we check all four boarders, we flip 'O' to 'X' means it get captured. and
// flip 'E' means 'O' means it get escape the capture.
public:
    char escape = 'E';
    vector<std::pair<int,int>> directions = {{0,1}, {0,-1}, {-1,0}, {1,0}};

    void solve(vector<vector<char>>& board) {
        int n_rows = board.size();
        int n_cols = board[0].size();

        for (int j=0; j<n_cols; j++) {
            bfs_helper(0, j, board); //check first row
            bfs_helper(n_rows-1, j, board); //check last row
        }
        for (int i=1; i<n_rows-1; i++) { // skip the four corners, becasue it is shared with first/last row.
            bfs_helper(i, 0, board); //check first col
            bfs_helper(i, n_cols-1, board); //check last col
        }
        for (int i=0; i<n_rows; i++) {
            for (int j=0; j<n_cols; j++) {
                if(board[i][j] == escape) {
                    board[i][j] = 'O';
                } 
                else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
    void bfs_helper(int row, int col, vector<vector<char>>& board) {
        if (board[row][col] == escape || board[row][col] =='X') {
            return;
        }
        std::queue<std::pair<int, int>> q;
        q.push(std::make_pair(row, col));
        board[row][col] = escape;

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int k=0; k<directions.size(); k++) {
                int new_x = x + directions[k].first;
                int new_y = y + directions[k].second;
                if (new_x>=0 && new_x<board.size() && new_y>=0 && new_y<board[0].size() && board[new_x][new_y]=='O') {
                    board[new_x][new_y] = escape;
                    q.push(std::make_pair(new_x, new_y));
                }
            }

        }
    }
};

// dfs version
class Solution2 {
public:
    char escape = 'E';
    vector<std::pair<int,int>> directions = {{0,1}, {0,-1}, {-1,0}, {1,0}};

    void solve(vector<vector<char>>& board) {
        int n_rows = board.size();
        int n_cols = board[0].size();

        for (int j=0; j<n_cols; j++) {
            dfs_helper(0, j, board); //check first row
            dfs_helper(n_rows-1, j, board); //check last row
        }
        for (int i=1; i<n_rows-1; i++) { // skip the four corners, becasue it is shared with first/last row.
            dfs_helper(i, 0, board); //check first col
            dfs_helper(i, n_cols-1, board); //check last col
        }
        for (int i=0; i<n_rows; i++) {
            for (int j=0; j<n_cols; j++) {
                if(board[i][j] == escape) {
                    board[i][j] = 'O';
                } 
                else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
    void dfs_helper(int x, int y, vector<vector<char>>& board) {
        if (board[x][y] == escape || board[x][y] =='X') {
            return;
        }
        board[x][y] = escape;

        for (int k=0; k<directions.size(); k++) {
            int new_x = x + directions[k].first;
            int new_y = y + directions[k].second;
            if (new_x>=0 && new_x<board.size() && new_y>=0 && new_y<board[0].size()) {
                dfs_helper(new_x, new_y, board);
            }
        }
    }
};





