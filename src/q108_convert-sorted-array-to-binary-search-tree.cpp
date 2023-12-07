/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <treenode.h>
#include <vector>

using std::vector;

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return traverse_and_set(nums, 0, nums.size()-1);
    }
    TreeNode* traverse_and_set(vector<int>& nums, int left, int right) {
        if (left>right) {
            return nullptr;
        }
        int mid_point = (left + right) / 2;

        TreeNode* root = new TreeNode(nums[mid_point]);
        root->left = traverse_and_set(nums, left, mid_point-1);
        root->right = traverse_and_set(nums, mid_point+1, right);

        return root;

    }
};