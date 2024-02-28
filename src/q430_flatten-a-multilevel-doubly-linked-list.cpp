
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

#include <stack>

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
#include <stack>


class Solution1 {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        
        // pseudo head to ensure the prev pointer is never none
        Node* sentinel_node = new Node;
        sentinel_node->next = head;

        flattenDfs(sentinel_node, head);

        // detach the pseudo head from the real head
        sentinel_node->next->prev = nullptr;
        return sentinel_node->next;
    }

    Node* flattenDfs(Node* prev, Node* curr) {
        // return the tail of the flatten list
        if (curr==nullptr) {
            return prev;
        }
        curr->prev = prev;
        prev->next = curr;

        // the curr->next would be tempered in the recursive function
        Node* temp_next = curr->next;
        Node* tail = flattenDfs(curr, curr->child);
        curr->child = nullptr;
        return flattenDfs(tail, temp_next);
    }

};


class Solution2 {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        std::stack<Node*> s;
        Node* rslt = head;
        Node* curr = head;
        Node* prev_ptr = new Node;
        prev_ptr->next = head;
        head->prev = prev_ptr;

        while (curr != nullptr || s.size()!=0) {
            if (curr!=nullptr) {
                if (curr->child == nullptr) {
                    prev_ptr = curr;
                    curr = curr->next;
                } else {
                    if (curr->next) {
                        s.push(curr->next);
                    }
                    Node* next_ptr = curr->child;
                    next_ptr->prev = curr;
                    curr->next = curr->child;
                    curr->child = nullptr;
                    prev_ptr = curr;
                    curr = next_ptr;
                }
            } else {
                Node* node = s.top();
                s.pop();
                node->prev = prev_ptr;
                prev_ptr->next = node;
                curr = node;
            }
        }
        rslt->prev = nullptr;
        return rslt; 
    }
};


class Solution3 {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        std::stack<Node*> s;
        Node* dummy_node = new Node;
        Node* prev = dummy_node;
        s.push(head);

        while (!s.empty()) {
            Node* curr = s.top();
            s.pop();
            prev->next = curr;
            curr->prev = prev;
            if (curr->next) {
                s.push(curr->next);
            }
            if (curr->child) {
                s.push(curr->child);
                curr->child = nullptr;
            }
            prev = curr;
        }
        Node* new_head = dummy_node->next;
        new_head->prev = nullptr;

        return new_head;
    }
};