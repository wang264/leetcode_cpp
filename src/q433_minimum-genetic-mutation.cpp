#include <queue>
#include <unordered_set>
#include <string>
#include <vector>

using std::string;
using std::vector;
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        char choices[4] = {'A', 'C', 'G', 'T'};
        std::unordered_set<string> bank_set;
        for (const auto& gene: bank) {
            bank_set.insert(gene);
        }
        std::queue<string> q;
        std::unordered_set<string> visited;
        q.push(startGene);
        visited.insert(startGene);

        int step = 0;
        while(!q.empty()) {
            int num_genes = q.size();
            for (int j=0; j<num_genes; j++) {
                string gene = q.front();
                q.pop();
                if (gene == endGene) {
                    return step;
                }
                for (auto c: choices) {
                    for(int i=0; i<gene.size(); i++) {
                        string mutated_gene = gene;
                        mutated_gene[i] = c;
                        if (visited.count(mutated_gene)==0 && 
                            bank_set.count(mutated_gene)==1) {
                            q.push(mutated_gene);
                            visited.insert(mutated_gene);
                        }
                    }
                }
            }
            step++;
        }
        return -1;

    }
};