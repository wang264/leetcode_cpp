#include <algorithm>
#include <queue>
#include <vector>

using std::vector;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<std::pair<int, int>> projects;
        for (int i=0; i<n; i++) {
            projects.emplace_back(capital[i], profits[i]);
        }
        std::sort(projects.begin(), projects.end());
        std::priority_queue<int> pq;
        int ptr=0;
        for (int i=0; i<k; i++) {
            while (ptr<n && projects[ptr].first <= w) {
                pq.push(projects[ptr].second);
                ptr++;
            }
            if (pq.empty()) {
                break;
            }
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};