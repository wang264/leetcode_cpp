#include<treenode.h>
#include<unordered_map>
#include<vector>

using std::vector;

class Solution {
public:
    std::unordered_map<int, int> inorder_map; // from: value---> index in preorder vector

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderidx = 0;
        for (int i=0; i<inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }

        return buildTreeHelper(preorder, 0, preorder.size()-1, preorderidx);
    }

    TreeNode* buildTreeHelper(const vector<int>& preorder, int left, int right, int& preorderidx) {
        if (left>right) return nullptr;

        int rootValue = preorder[preorderidx];
        preorderidx++;
        TreeNode* node = new TreeNode(rootValue);

        node->left = buildTreeHelper(preorder, left, inorder_map[rootValue]-1, preorderidx);
        node->right = buildTreeHelper(preorder, inorder_map[rootValue]+1, right, preorderidx);
        return node;

    }
};