#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> rslt;
        vector<int> path;
        dfs(n, k, 1, path, rslt);
        return rslt;
    }
    // j = current number
    void dfs(int n, int k, int j, vector<int>& path, vector<vector<int>>& rslt) {
        if (path.size() == k) {
            rslt.push_back(path);
            return;
        }

        for (int curr = j; curr<=n; curr++) {
            path.push_back(curr);
            curr++;
            dfs(n, k, curr, path, rslt);
            curr--;
            path.pop_back();
        }
    }
};