#include <treenode.h>
#include <limits.h>
#include <algorithm>  //std::min std::max

class Solution {
public:
    int min_abs_diff = 10000000;

    int getMinimumDifference(TreeNode* root) {
       traverse(root);
       return min_abs_diff; 
    }
    // return pair of max, min value of this tree.
    std::pair<int, int> traverse(TreeNode* root) {
        if (!root) {
            return std::make_pair(-10000000, +10000000);
        }

        auto [left_max, left_min] = traverse(root->left);
        auto [right_max, right_min] = traverse(root->right);

        int tree_max = std::max(right_max, root->val);
        int tree_min = std::min(left_min, root->val);
        min_abs_diff = std::min(min_abs_diff, std::abs(root->val - left_max));
        min_abs_diff = std::min(min_abs_diff, std::abs(root->val - right_min));

        return std::make_pair(tree_max, tree_min);
    }

};

int main() {
    return 0;
}


// g++ -std=c++17 -o q530_minimum-absolute-difference-in-bst q530_minimum-absolute-difference-in-bst.cpp -I ../

class Solution {
public:
    int min_abs_diff = INT_MAX;
    TreeNode* prev_node = nullptr;

    void inorderTraversal(TreeNode* node) {
        if (!node) {
            return;
        }
        inorderTraversal(node->left);
        if (prev_node) {
            min_abs_diff = std::min(min_abs_diff, node->val - prev_node->val);
        }
        prev_node = node;
        inorderTraversal(node->right);
    }

    int getMinimumDifference(TreeNode* root) {
       inorderTraversal(root);
       return min_abs_diff; 
    }
};
