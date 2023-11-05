#include<listnode.h>

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
    if (!head) return nullptr;
    if (k==0) return head;

    int length = 0;
    ListNode* ptr = head;
    while(ptr) {
        length++;
        ptr = ptr->next;
    }
    
    k = k % length;
    if (k==0) {return head;}
    
    ListNode* first = head;
    ListNode* second = head;
    // first we let the first pointer move k step, then we start move them together and make
    // sure there are k-1 nodes in between. so when first->next==nullptr, second will point to a node 
    // and that node's next would be the node we want to cut and past infont of head;
    for(int i=0; i<k; i++) {first=first->next;}

    while(first->next) {
        first=first->next;
        second = second->next;
    }

    ListNode* newHead = second->next;
    //disconnect to two sublist and coneect two sublist.
    second->next =nullptr;
    first->next = head;

    return newHead;


    }
};