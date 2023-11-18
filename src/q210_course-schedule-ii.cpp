#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>


using std::vector;


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::unordered_map<int, std::unordered_set<int>> graph;
        std::unordered_map<int, int> node_2_indegree;
        vector<int> rslt;

        // build graph pre_req--->course
        for (int i=0; i<numCourses; i++) {
           node_2_indegree[i]=0;
           graph[i];
        }
        for (auto& element: prerequisites) {
           int course = element[0];
           int pre_req = element[1];
           graph[pre_req].insert(course);
           node_2_indegree[course]++;
        }
        std::unordered_set<int> visited;
        // find node that have zerop in_degree
        std::queue<int> q;
        for (auto e: node_2_indegree) {
            if(e.second ==0) {
                q.push(e.first);
                visited.insert(e.first);
                rslt.push_back(e.first);
           }
        }
        while(!q.empty()) {
            int course = q.front();
            q.pop();

            for (const int& next_course: graph[course]) {
                node_2_indegree[next_course]--;
                if (node_2_indegree[next_course]==0) {
                    visited.insert(next_course);
                    rslt.push_back(next_course);
                    q.push(next_course);
                }
            }
        }
        return rslt.size()==numCourses ? rslt : vector<int>();
    }
};