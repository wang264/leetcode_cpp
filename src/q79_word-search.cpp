#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
    vector<int> xDirections = {0 ,0, -1, 1};
    vector<int> yDirections = {1 ,-1, 0, 0};
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited;
        for (int i=0; i<board.size(); i++) {
            visited.push_back(vector(board[0].size(), false));
        }
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                visited[i][j] = true;
                bool found = dfs(board, visited, word, 0, i, j);
                visited[i][j] = false;
                if (found) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int idx, int i, int j) {
        if (board[i][j] != word[idx]) {
            return false;
        }
        if (idx==word.size()-1) {
            return true; // we find the match
        }
        bool found = false;
        for (int k=0; k<4; k++) {
            int dx = xDirections[k];
            int dy = yDirections[k];
            int x = i + dx;
            int y = j + dy;
            if (x>=0 && x< board.size() && y>=0 && y<board[0].size() && !visited[x][y]) {
                visited[x][y] = true;
                found = dfs(board, visited, word, idx+1, x, y);
                visited[x][y] = false;
                if (found) {
                    return true;
                }
            }
        }
        return found;
    }
};