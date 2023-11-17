#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>

using std::vector;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {return node;}

        std::unordered_map<Node*, Node*> my_map;
        std::unordered_set<Node*> visited;
        
        std::queue<Node*> q;
        visited.insert(node);
        q.push(node);

        // create new node use bfs.
        while(!q.empty()) {
            Node* old_node = q.front();
            q.pop();
            Node* new_node = new Node(old_node->val);
            my_map[old_node] = new_node;
            for (Node* neighbor: old_node->neighbors) {
                if (visited.count(neighbor)==0) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }

        //set the neighbors for newly created node.
        for (auto iter = visited.begin(); iter != visited.end(); ++iter) {
            Node* old_node = *iter;
            Node* new_node = my_map[old_node];

            for (Node* neighbor: old_node->neighbors) {
                new_node->neighbors.push_back(my_map[neighbor]);
            }

        }
        
        return my_map[node];
    }
};











