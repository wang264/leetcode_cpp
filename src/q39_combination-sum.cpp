#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> rslt;
        vector<int> path;
        dfs(candidates, target, path, rslt);
        return rslt;
    }

    void dfs(vector<int>& candidates, int target, vector<int>& path, vector<vector<int>>& rslt) {
        if (target == 0) {
            rslt.push_back(path);
            return;
        } else if (target<0) {
            return;
        }

        for (const int& num: candidates) {
            if (!path.empty() && num < path.back()) {
                continue;
            } else {
                path.push_back(num);
                dfs(candidates, target-num, path, rslt);
                path.pop_back();
            }
        }
    }
};