#include <string>
#include <vector>
#include <unordered_set>

using std::vector;
using std::string;


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        std::unordered_set<string> set(wordDict.begin(), wordDict.end());
        vector<bool> dp(n+1, false);
        // dp[i]: possible to form first i letter in s with word in wordDict.
        dp[0] = true;
        for (int i=1; i<=n; i++) {
            for (int j=0; j<i; j++) {
                string substring = s.substr(j, i-j);
                if (dp[j] && set.contains(substring)) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};


class Solution2 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false); 
        //dp[i]: possible or not to form the stirng 's' from index 0 to index i, with using word in wordDict
        for (int i=0; i<s.length(); i++) {
            for(const string word: wordDict) {
                //out of bound case
                if (i<word.length()-1) {
                    continue;
                }
                if (i==word.length()-1 || dp[i-word.length()]) {
                    string substring = s.substr(i-word.length()+1, word.length());
                    if (substring == word) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        
        return dp[s.length()-1];
    }
};
