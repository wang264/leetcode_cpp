#include <queue>
#include <algorithm>  //std::pair
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        
        std::queue<std::pair<Node*, int>> q;
        int level = 0;
        q.push(std::make_pair(root, level));

        while (!q.empty()) {
            std::pair<Node*, int> pair = q.front();
            q.pop();
            Node* node = pair.first; 
            int val = node->val;
            int curr_lvl = pair.second;

            if (!q.empty()) {
                Node* next = nullptr;
                if (q.front().second == curr_lvl) {
                    next = q.front().first;
                }
                node->next = next;
            }
            if (node->left) {
                q.push(std::make_pair(node->left, curr_lvl+1));
            }
            if (node->right) {
                q.push(std::make_pair(node->right, curr_lvl+1));
            }
        }
        return root;
    }
};