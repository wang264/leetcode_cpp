#include<treenode.h>
#include <tuple>

 // ????
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool a_in_tree; 
        bool b_in_tree;
        TreeNode* lca;
        std::tie(a_in_tree, b_in_tree, lca) = lcaHelper(root, p, q);  
        return lca;  
    }
    std::tuple<bool, bool, TreeNode*> lcaHelper(TreeNode* root, TreeNode* node_a, TreeNode* node_b) {
        if (!root) {
            return std::make_tuple(false, false,  nullptr);
        }
        bool a_in_left; bool b_in_left;
        TreeNode* lca_left;
        bool a_in_right; bool b_in_right;
        TreeNode* lca_right;

        std::tie(a_in_left, b_in_left, lca_left) = lcaHelper(root->left, node_a, node_b);
        std::tie(a_in_right, b_in_right, lca_right) = lcaHelper(root->right, node_a, node_b);

        bool a_in_tree = a_in_left || a_in_right || (root == node_a);
        bool b_in_tree = b_in_left || b_in_right || (root == node_b);

        if (a_in_tree && b_in_tree) {
            if (!lca_left && !lca_right) {
                return std::make_tuple(true, true, root);
            } else if (lca_left && !lca_right) {
                return std::make_tuple(true, true, lca_left);
            } else if (!lca_left && lca_right) {
                return std::make_tuple(true, true, lca_right);
            } else {
                return std::make_tuple(true, true, nullptr); //case will never hit.
            }

        } else {
            // if either of A or B does not exist in this tree. it means no LCA, so we return None for LCA.
            return std::make_tuple(a_in_tree, b_in_tree, nullptr);
        }
    }
};