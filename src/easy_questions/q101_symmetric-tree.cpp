#include<treenode.h>

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }

    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) {return true;}
        else if (!t1 || !t2) {return false;}
        else {
            return (t1->val == t2->val && isMirror(t1->right, t2->left) && isMirror(t1->left, t2->right));
        }
    }
};

