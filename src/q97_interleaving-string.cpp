#include <string>
#include <vector>

using std::string;


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    // let A=s1, B=s2, X=s3
    // dp[i][j] = X的前i+j个字符是否为A的前i个字符和B的前j个字符交替组成。
    // A的长度为m, B的长度为n,X的长度是m+n
    // 我们看最后一步，假设X是由A和B交错形成的，那么X的最后一个字符X[m+n-1]有两种情况。
    
    // 情况一：X的最后一个字符X[m + n - 1] 是由A的最后一个字符A[m-1]组成的，那么
    // X[0.....m+n-2] 则由A[0...m-2] 和 B[0...n-1]交错形成的
    
    // 情况二：X的最后一个字符X[m + n - 1] 是由的最后一个字符B[n-1]组成的，那么
    // X[0.....m+n-2] 则由A[0...m-1] 和 B[0...n-2]交错形成的
        int m = s1.size();
        int n = s2.size();
        string A = s1;
        string B = s2;
        string X = s3;
        if (m+n!=X.size()) {
            return false;
        }
        std::vector<std::vector<bool>> dp(m+1, std::vector<bool>(n+1, false));
        for (int i=0; i<=m; i++) {
            for (int j=0; j<=n; j++) {
                if (i==0 && j==0) {
                    dp[0][0]=true;
                    continue;
                }
                // case 1 
                if (i>0 && X[i+j-1]==A[i-1] && dp[i-1][j]) {
                    dp[i][j] = true;
                } else if (j>0 && X[i+j-1]==B[j-1] && dp[i][j-1]) {
                    dp[i][j] = true;
                }
            }
        }
        return dp[m][n];
    }
};