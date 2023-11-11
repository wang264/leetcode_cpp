
#include<queue>
#include<treenode.h>

using std::vector;

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> rslt;
        std::queue<TreeNode*> q;

        if (root) {q.push(root);}

        while(!q.empty()) {
            int lvl_size = q.size();
            double sum = 0.0;
            for(int i=0; i<lvl_size; i++) {
                TreeNode* node = q.front();
                q.pop();
                sum+=node->val;
                if(node->left) {q.push(node->left);}
                if(node->right) {q.push(node->right);}
            }
            double lvl_avg = sum / lvl_size;
            rslt.push_back(lvl_avg);
        }

        return rslt;

    }
};