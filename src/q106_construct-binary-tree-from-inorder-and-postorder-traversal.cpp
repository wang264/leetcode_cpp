// similar to q105
#include<treenode.h>
#include<unordered_map>
#include<vector>

using std::vector;

class Solution {
public:
    std::unordered_map<int, int> inorder_map; // from: value---> index in preorder vector

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postorderidx = postorder.size()-1;
        for (int i=0; i<inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }

        return buildTreeHelper(postorder, 0, postorder.size()-1, postorderidx);
    }
    TreeNode* buildTreeHelper(const vector<int>& postorder, int left, int right, int& postorderidx) {
        if (left>right) return nullptr;

        int rootValue = postorder[postorderidx];
        postorderidx--;
        TreeNode* node = new TreeNode(rootValue);

        node->right = buildTreeHelper(postorder, inorder_map[rootValue]+1, right, postorderidx);
        node->left = buildTreeHelper(postorder, left, inorder_map[rootValue]-1, postorderidx);
        return node;

    }
};
