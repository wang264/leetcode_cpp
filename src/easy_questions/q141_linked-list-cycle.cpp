#include<listnode.h>
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {return false;}

        ListNode dummy = ListNode(-1);
        dummy.next = head;

        ListNode* slow = &dummy;
        ListNode* fast = head;

        while (slow!=fast && fast->next != nullptr && (fast->next)->next != nullptr ) {
            slow = slow->next;
            fast = (fast->next)->next;
        }

        return slow==fast;
    }
};


int main() {
    return 0;
}

//// g++ -std=c++11 -o q141_linked-list-cycle q141_linked-list-cycle.cpp