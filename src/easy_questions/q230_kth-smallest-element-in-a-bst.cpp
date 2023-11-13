
#include <treenode.h>
#include <stack>

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> my_stack;

        TreeNode* curr = root;
        while (curr || !my_stack.empty()) {
            while (curr) {
                my_stack.push(curr);
                curr = curr->left;
            }
            curr = my_stack.top();
            my_stack.pop();
            k--;
            if (k==0) {
                return curr->val;
            }
            curr = curr->right;
        }        
    return 0;
    }
};