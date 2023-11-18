#include<vector>
#include<queue>

#include <numeric> //std::iota


using std::vector;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int label = 1;
        // need to find a map from label --> x, y cordinate in the board.
        vector<std::pair<int, int>> cord(n*n+1);
        vector<int> columns(n);
        std::iota(columns.begin(), columns.end(), 0);
        for (int row=n-1; row>=0; row--) {
            for (int col: columns) {
                cord[label] = std::make_pair(row, col);
                label++;
            }
            std::reverse(columns.begin(), columns.end());
        }
    
        vector<int> distance(n*n+1, -1); 
        //distance[i] would be the minimum step to get to label i.  we also overload this array as the "visited array"(if value is -1, means we never visit this position.)
        distance[1]=0;
        std::queue<int> q;
        q.push(1);

        while (!q.empty()) {
            int curr_pos = q.front();
            q.pop();
            for (int next_pos=curr_pos+1; next_pos<=std::min(curr_pos+6, n*n); next_pos++) {
                auto [row, col] = cord[next_pos];
                int destination = next_pos;
                if (board[row][col]!=-1) { //get a snake and ladder
                    destination=board[row][col];
                }
                if (destination == n*n) {
                    return distance[curr_pos] +1;
                }
                if (distance[destination]==-1) { //never visit this position
                    distance[destination] = distance[curr_pos] + 1;
                    q.push(destination);
                }
            }
        }
        return distance[n*n];
    }
};

int main() {
    return 0;
}

// g++ -std=c++17 -o q909_snakes-and-ladders q909_snakes-and-ladders.cpp