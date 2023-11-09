#include<./treenode.h>

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p && q) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right) && (p->val==q->val);
        } else if (!p && !q) {
            return true;
        } else {
            return false;
        }
    }
};