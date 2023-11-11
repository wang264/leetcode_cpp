#include <queue>
#include <vector>
#include<treenode.h>

using std::vector;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> rslt;
        std::queue<TreeNode*> q;

        if (root) {q.push(root);}

        while(!q.empty()) {
            int lvl_size = q.size();
            vector<int> rslt_this_lvl;
            for(int i=0; i<lvl_size; i++) {
                TreeNode* node = q.front();
                q.pop();
                rslt_this_lvl.push_back(node->val);
                if(node->left) {q.push(node->left);}
                if(node->right) {q.push(node->right);}
            }
            rslt.push_back(rslt_this_lvl);
        }

        return rslt;
    }
};