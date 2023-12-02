class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> rslt;
        vector<int> path;
        std::unordered_set<int> visited;
        dfs(nums, path, visited, rslt);
        return rslt;
    }
    void dfs(vector<int>& nums, vector<int>& path, std::unordered_set<int>& visited, vector<vector<int>>& rslt) {
        if (path.size() == nums.size()) {
            rslt.push_back(path);
            return;
        }
        for (const auto& num: nums) {
            if (!visited.count(num)) {
                visited.insert(num);
                path.push_back(num);
                dfs(nums, path, visited, rslt);
                path.pop_back();
                visited.erase(num);
            }
        }
    }
};