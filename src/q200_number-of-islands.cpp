#include <queue>
#include <vector>

using std::vector;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n_rows = grid.size();
        int n_cols = grid[0].size();
        int count = 0;
        char visited = '2';
        int dxs [4] = {0,  0, -1, 1};
        int dys [4] = {-1, 1, 0, 0};

        for (int i=0; i<n_rows; i++) {
            for (int j=0; j<n_cols; j++) {
                if (grid[i][j] == '1' && grid[i][j]!=visited) {
                    count++;
                    std::queue<std::pair<int, int>> q;
                    q.push(std::make_pair(i,j));
                    grid[i][j] = visited;
                    while(!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        for (int k=0;k<4;k++) {
                            int new_x = x+dxs[k];
                            int new_y = y+dys[k];
                            if (new_x>=0 && new_x<n_rows && new_y>=0 && new_y<n_cols && 
                                grid[new_x][new_y]!=visited && grid[new_x][new_y]=='1') 
                            {
                                grid[new_x][new_y] = visited;
                                q.push(std::make_pair(new_x, new_y));
                            }
                        }

                    }
                }
            }
        }
        return count;

    }
};