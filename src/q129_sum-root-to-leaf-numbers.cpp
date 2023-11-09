#include<stack>
#include<treenode.h>
#include<algorithm>

//iterative
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        std::stack<std::pair<TreeNode*, int>> my_stack; //std::pair.second is used to store the current number we have so far.
        my_stack.push(std::make_pair(root, 0));

        while (!my_stack.empty()) {
            auto pair = my_stack.top();
            TreeNode* node = pair.first;
            int curr_num = pair.second;
            my_stack.pop();

            if (node) {
                curr_num = curr_num*10 + node->val;
                if (!node->left && !node->right) {
                    sum += curr_num;
                } else {
                    my_stack.push(std::make_pair(node->right, curr_num));
                    my_stack.push(std::make_pair(node->left, curr_num));
                }
            }
        }
        return sum;

        
    }
};


 // recursive pre order.
class Solution {
public:
    int sum;

    int sumNumbers(TreeNode* root) {
        sum=0;
        preOrderTraverse(root, 0);
        return sum;
    }

    void preOrderTraverse(TreeNode* node, int curr_num) {
        if (!node) {
            return;
        }
        curr_num = curr_num*10 + node->val;

        if (!node->left && !node->right) {
            sum+=curr_num;
        } else {
            preOrderTraverse(node->left, curr_num);
            preOrderTraverse(node->right, curr_num);
            
        }
    }
};
