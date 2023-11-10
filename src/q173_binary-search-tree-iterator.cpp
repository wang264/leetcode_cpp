#include<treenode.h>
#include<stack>

class BSTIterator {

private:
    std::stack<TreeNode*> my_stack;

    void push_left(TreeNode* node) {
        while(node) {
            my_stack.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        push_left(root);
    }
    
    int next() {
        TreeNode* top_node = my_stack.top();
        my_stack.pop();
        if (top_node->right) {
            push_left(top_node->right);
        }
        return top_node->val;
    }
    
    bool hasNext() {
        return !my_stack.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */