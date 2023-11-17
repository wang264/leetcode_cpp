#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        auto g = buildGraph(equations, values);
        vector<double> rslt;

        for (auto& query: queries) {
            string dividend = query[0];
            string divisor = query[1];

            if (g.count(dividend)==0 || g.count(divisor)==0) {
                rslt.push_back(-1);
            } else{
                std::unordered_set<string> visited;
                double answer=-1;
                dfs_helper(dividend, divisor, g, visited, answer, 1.0);
                rslt.push_back(answer);
                
            }
        }

        return rslt;
    }
    void dfs_helper(string begin, 
                    string destination, 
                    std::unordered_map<string, std::unordered_map<string, double>>& g,
                    std::unordered_set<string>& visited,
                    double& answer, 
                    double temp) {
            if (visited.count(begin)==1) {return;}

            visited.insert(begin);
            if (begin == destination) {
                answer = temp;
                return;
            }

            for (auto& neighbor: g[begin]) {
                dfs_helper(neighbor.first, destination, g, visited, answer, temp*neighbor.second);
            }


    }
    std::unordered_map<string, std::unordered_map<string, double>> buildGraph(
       vector<vector<string>>& equations,
       vector<double>& values
    ) {
        std::unordered_map<string, std::unordered_map<string, double>> g;

        for (int i=0; i<equations.size(); i++) {
            string dividend = equations[i][0];
            string divisor = equations[i][1];

            g[dividend][divisor] = values[i];
            g[divisor][dividend] = 1/values[i];
        }
        return g;
    }
};