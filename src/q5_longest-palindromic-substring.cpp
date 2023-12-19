#include <string>
#include <vector>

using std::vector;
using std::string;

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        //dp[i][j]: the substring s[i]....s[j] of s is a valid palindrome.
        std::pair<int, int> answer = std::make_pair(0, 0);

        //length =1 
        for (int i=0; i<s.size(); i++) {
            dp[i][i] = true;
        }
        //length =2    
        for (int i=1; i<s.size(); i++) {
            if (s[i-1]==s[i]) {
                dp[i-1][i] = true;
                answer.first= i-1;
                answer.second= i;
            }
        }

        // length = 3 and onward
        for (int diff=2; diff<s.size(); diff++) {
            for (int i=0; i<s.size() - diff; i++) {
                int j = i + diff;
                if (s[i]==s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    answer.first = i;
                    answer.second = j;
                }
            }
        }

        return s.substr(answer.first, answer.second-answer.first+1);

    }
};

// diff=4
// s size =6 
// a b c d e f
// |       |     