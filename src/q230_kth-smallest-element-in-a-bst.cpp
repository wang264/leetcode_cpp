#include<treenode.h>

#include <stack>

class Solution1 {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        int answer=-1;
        traverse(root, count, answer, k);
        return answer;
    }
    void traverse(TreeNode* root, int& count, int& answer, int k) {
        if (!root) {return;}

        traverse(root->left, count, answer, k);
        count++;
        if (count==k) {
            answer = root->val;
            return;
        }
        traverse(root->right, count, answer, k);
    }
};

class Solution2 {
public:
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> my_stack;

        TreeNode* curr = root;
        while (curr || !my_stack.empty()) {
            while (curr) {
                my_stack.push(curr);
                curr = curr->left;
            }
            curr = my_stack.top();
            my_stack.pop();
            k--;
            if (k==0) {
                return curr->val;
            }
            curr = curr->right;
        }        
    return 0;
    }
};

