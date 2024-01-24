
#include <treenode.h>
#include <stack>
#include <limits.h>

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

class Solution2 {
public:
    bool search(TreeNode* root, int min_val, int max_val) {
        
        // (min_val, max_val) store the min and max value for root to be valid. 
        if (root==nullptr) {
            return true;
        }
        if (root->val <= min_val || root->val >= max_val) {
            return false;
        }
        return search(root->left, min_val, root->val) && search(root->right, root->val, max_val);
    }
    bool isValidBST(TreeNode* root) {
        return search(root, INT_MIN, INT_MAX);
    }
};
