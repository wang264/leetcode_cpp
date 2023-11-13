
#include <treenode.h>
#include <stack>

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        std::stack<TreeNode*> my_stack;
        TreeNode* curr = root;
        TreeNode* prev = nullptr;

        while (curr || !my_stack.empty()) {
            while (curr) {
                my_stack.push(curr);
                curr = curr->left;
            }
            curr = my_stack.top();
            my_stack.pop();
            if (prev && curr->val <= prev->val) {
                return false;
            }
            prev = curr;
            curr = curr->right;
        }

        return true;
    }
};