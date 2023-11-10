#include<treenode.h>
#include <stack>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> rslt;
        std::stack<TreeNode*> my_stack;
        TreeNode* curr = root;
        while (curr || !my_stack.empty()) {
            while(curr) {
                my_stack.push(curr);
                curr = curr->left;
            }
            curr = my_stack.top();
            my_stack.pop();
            rslt.push_back(curr->val);
            curr = curr->right;
        }
        return rslt;
    }
};