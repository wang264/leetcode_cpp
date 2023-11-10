#include<treenode.h>
#include <limits.h>
#include <algorithm>    // std::max

class Solution {
public:
    int max_path;

    int maxPathSum(TreeNode* root) {
        max_path = INT_MIN;
        gain_from_subtree(root);
        return max_path;
    }
    int gain_from_subtree(TreeNode* node) {
        if (!node) {
            return 0;
        }

        // add the gain from the left subtree. Note that if the gain is negative, we can 
        // ignore it, or count it as 0. This is the reason we use `max` here.
        int gain_from_left = std::max(gain_from_subtree(node->left), 0);
        int gain_from_right = std::max(gain_from_subtree(node->right), 0);
        
        //if left or right gain are negative, they are counted as 0, so this statement 
        // takes care of all four scenarios
        max_path = std::max(max_path, gain_from_left + gain_from_right + node->val);

        // return the max sum for a path starting at the root of subtree
        return std::max(gain_from_left + node->val, gain_from_right + node->val);

    }
};