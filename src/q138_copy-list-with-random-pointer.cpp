#include <unordered_map>


using std::unordered_map;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
    if (!head) return nullptr;

    //use a map to store oldNode--->newNode; 
    unordered_map<Node*, Node*> map; // map from Node in Old list to new list. 

    // first create the new linked list;
    Node* dummy = new Node(-1);
    Node* prev = dummy;
    Node* old_head = head;
    while (old_head) {
        Node* curr = new Node(old_head->val);
        map[old_head] = curr;
        prev->next = curr;
        prev = prev->next;
        old_head = old_head->next;
    }


    // then fix their random pointer. 
    Node* old_node = head;
    while (old_node) {
        Node *new_node = map[old_node];
        if (old_node->random) {
            new_node->random = map[old_node->random]; // use the map to get the random pointer.
        }
        old_node = old_node->next;
    } 
    return dummy->next;
    }
};