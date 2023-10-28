#include<vector>
#include<unordered_set>


using std::vector; 
using std::unordered_set;


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        //check each row
        unordered_set<char> rows[9]; // to store the numbers for each row
        unordered_set<char> cols[9]; // to store the numbers in each colmuns.
        unordered_set<char> boxes[9]; //to store each numbers in sub-boxes.

        for (int i=0;i<9;i++) {
            for (int j=0;j<9;j++) {
                char c = board[i][j];
                if (c == '.') {continue;}

                if (rows[i].count(c)>0) {
                    return false;
                }
                rows[i].insert(c);

                if (cols[j].count(c)>0) {
                    return false;
                }
                cols[j].insert(c);

                int box_num = (i/3)*3 + j/3;
                if (boxes[box_num].count(c)>0) {
                    return false;
                }
                boxes[box_num].insert(c);

            }
        }
        return true;

        
    }
};