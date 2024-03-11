#include<vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original_color = image[sr][sc];
        int target_color = color;
        if (original_color == target_color) {
            return image;
        }
        dfs_helper(image, sr, sc, original_color, target_color);
        return image;
    }
    void dfs_helper(vector<vector<int>>& image, int sr, int sc, int original_color, int target_color) {
        if (image[sr][sc]==original_color) {
            image[sr][sc]=target_color;
            for (const auto& direction: directions) {
                int dx = direction[0];
                int dy = direction[1];
                int next_x = sr+dx;
                int next_y = sc+dy;
                if (next_x>=0 && next_x<image.size() && next_y>=0 && next_y<image[0].size()) {
                    dfs_helper(image, next_x, next_y, original_color, target_color);
                }
            }
        } else {
            return;
        }
    }
};