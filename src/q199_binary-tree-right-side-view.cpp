#include<treenode.h>
#include <queue>
#include<vector>

using std::vector;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rslt;
        std::queue<TreeNode*> q; 
        if (root) {
            q.push(root);
        }

        while(!q.empty()) {
            int lvl_size = q.size();
            for (int i=0; i<lvl_size; i++)
            {
                auto node = q.front(); 
                q.pop();

                if (i == lvl_size-1) {
                    rslt.push_back(node->val);
                }
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        return rslt;
    }
};