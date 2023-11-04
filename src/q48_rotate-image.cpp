#include<vector>


using std::vector;


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    // for roate 90 degrees clockwiase.
    // for matrix n*n, (i, j) --> (j, n-i-1) 

    //Approach 2: Reverse on Diagonal(transpose) and then Reverse Left to Right
        int n = matrix.size();
        transpose(matrix, n);
        reflect(matrix, n);
    }
    void transpose(vector<vector<int>>& m, int n) {
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                std::swap(m[i][j], m[j][i]);
            }
        }
    }

    void reflect(vector<vector<int>>& m, int n) {
        for (int i=0; i<n; i++) {
            for (int j=n/2; j<n; j++) {
                std::swap(m[i][j], m[i][n-j-1]);
            }
        }
    }
};