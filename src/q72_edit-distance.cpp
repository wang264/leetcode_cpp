#include <string>
#include <vector>

using std::string;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // A = word1   B = word2
        // 假设A的长度是m, B的长度是n. 全部操作完成后A的长度也是n， 并且A[n-1]= B[n-1]
        // 于是最优策略（以及所有合法策略）最终都是让A的最后一个字符变成B的最后一个字符。

        // 请况一：增加，在A的最后插入B[n-1]这个字符,  要将A[0...m-1]变成B[0...n-2]
        // 请况二：替换，把A的最后一个字符变成B[n-1]这个字符， 要将A[0...m-2]变成B[0...n-2]
        // 请况三：删除，先把A的最后一个字符删掉，然后再说。 要将A[0...m-2]变成B[0...n-1]
        // 情况四：A[m-1]等于B[n-1],天然相等。要将A[0...m-2]变成B[0...n-２]

        // dp[i][j] = A的前i个字符（A[0...i-1])和B的前j个字符（B[0...j-1])的最小编辑距离
        int m = word1.size();
        int n = word2.size();
        string A = word1;
        string B = word2;
        std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1, 0));
        
        for (int i=0; i<m+1; i++) {
            for (int j=0; j<n+1; j++) {
                if (i==0 && j==0) {
                    dp[i][j] = 0;
                    continue;
                }
                if (i==0) {
                    dp[i][j] = j;
                    continue;
                }
                if (j==0) {
                    dp[i][j] = i;
                    continue;
                }
                dp[i][j] = dp[i][j-1] + 1; //case 1
                dp[i][j] = std::min(dp[i][j], dp[i-1][j-1] + 1); //case 2
                dp[i][j] = std::min(dp[i][j], dp[i-1][j] + 1); //case 3
                if (A[i-1]==B[j-1]) {
                    dp[i][j] = std::min(dp[i][j], dp[i-1][j-1]); // case 4
                }
                

            }
        }
        return dp[m][n];
    }
};