#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int h = triangle.size();
        for (int i=1; i<h; i++) { // for each level
            for (int j=0; j<=i; j++) {  //from left to right
                if (j==0) { //left edge.
                    triangle[i][0] += triangle[i-1][0];
                } else if(j==i) { //right edge.
                    triangle[i][j] += triangle[i-1][j-1];
                } else { //generic case.
                    int min_prev = std::min(triangle[i-1][j-1],triangle[i-1][j]);
                    triangle[i][j] += min_prev;
                }
            }
        }

        return *std::min_element(triangle[h-1].begin(), triangle[h-1].end());
    }
};