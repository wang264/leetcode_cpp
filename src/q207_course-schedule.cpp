#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using std::vector;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       std::unordered_map<int, std::unordered_set<int>> graph;
       std::unordered_map<int, int> node_2_indegree;
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
           }
       }
       //use bfs to iterate through the map.
       while (!q.empty()) {
           int course = q.front();
           q.pop();
           for (const int& next_course: graph[course]) {
               node_2_indegree[next_course]--;
               if (node_2_indegree[next_course]==0) {
                   visited.insert(next_course);
                   q.push(next_course);
               }
           }

       }
       return visited.size()==numCourses ? true : false;
    }
    void dfs_helper(int preq, 
                    std::unordered_map<int, std::unordered_set<int>>& graph,
                    std::unordered_set<int>& visited) {
        for (auto e: graph[preq]) {
            if(visited.count(e)==0) {
                visited.insert(e);
                dfs_helper(e, graph, visited);
            }
        }

    }
};