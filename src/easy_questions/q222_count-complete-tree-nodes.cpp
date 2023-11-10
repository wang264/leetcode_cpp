#include<treenode.h>
#include <cmath> //std::pow

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int left_height = 0;
        int right_height = 0;
        TreeNode* left = root;
        TreeNode* right = root;
        while (left) {
            left_height++;
            left = left->left;
        }
        while (right) {
            right_height++;
            right = right->right;
        }
        if (left_height == right_height) {
            return std::pow(2, left_height)-1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right); 
    }
};