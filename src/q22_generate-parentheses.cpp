#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> rslt;
        vector<char> path;
        dfs(n, 0, 0, path, rslt);
        return rslt;
    }

    void dfs(int n, int left_count, int right_count, vector<char>& path, vector<string>& rslt) {
        if (path.size() == 2*n) {
            rslt.push_back(string(path.begin(), path.end()));
            return;
        }
        if (left_count<n) {
            path.push_back('(');
            dfs(n, left_count+1, right_count, path, rslt);
            path.pop_back();
        }
        if (left_count>right_count) {
            path.push_back(')');
            dfs(n, left_count, right_count+1, path, rslt);
            path.pop_back();
        }
    }
};