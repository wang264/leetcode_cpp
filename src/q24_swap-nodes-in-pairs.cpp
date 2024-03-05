#include<listnode.h>
// Input: head = [1,2,3,4]
// Output: [2,1,4,3]
class Solution1 {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next){return head;}

        //node to be swapped.
        ListNode* first_node = head;
        ListNode* second_node = head->next;

        //swapping
        first_node->next = swapPairs(second_node->next);
        second_node->next = first_node;

        // Now the head is the second node
        return second_node;

    }
};

class Solution2 {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head==nullptr || head->next==nullptr) {
            return head;
        }
        ListNode* dummy = new ListNode(-1, head);
        ListNode* prev = dummy;
        ListNode* first = prev->next;
        while (first) {
            ListNode* second = first->next;
            if (!second) {
                break;
            }
            ListNode* new_first = second->next;
            prev->next = second;
            second->next = first;
            first->next = new_first;
            prev =first;
            first = new_first;
        }

        return dummy->next;
    }
};