#include<treenode.h>

// recursive solution
class Solution {
public:
    void flatten(TreeNode* root) {
        flattenHelper(root);

    }

    TreeNode* flattenHelper(TreeNode* node) {
        if (!node) {
            return nullptr;
        }
        // for leaf nove, we return the node as is.
        if (!node->left && !node->right) {
            return node;
        }

        TreeNode* leftTail = flattenHelper(node->left);
        TreeNode* rightTail = flattenHelper(node->right);

        // If there was a left subtree, we shuffle the connections
        // around so that there is nothing on the left side anymore.
        if (leftTail) {
            leftTail->right = node->right;
            node->right = node->left;
            node->left = nullptr;   
        }
        // We need to return the "rightmost" node after we are
        // done wiring the new connections.
        return rightTail ? rightTail : leftTail;
    }

};

// ???
//iterative solution.
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root){
            return;
        }
        TreeNode *curr = root;
        while(curr){
            if(curr->left){
                TreeNode *pre = curr->left;
                while(pre->right){
                    pre = pre->right;
                }
                pre->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};