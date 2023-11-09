#include<listnode.h>

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode* dummyLessThan = new ListNode();
        ListNode* dummyEqualOrGreater = new ListNode();

        ListNode* ptr_1 = dummyLessThan;
        ListNode* ptr_2 = dummyEqualOrGreater;

        ListNode* curr = head;
        
        while (curr) {
            ListNode* next = curr->next;
            if (curr->val < x) {
                ptr_1->next = curr;
                ptr_1 = ptr_1->next;
                ptr_1->next = nullptr;
            } else {
                ptr_2->next = curr;
                ptr_2 = ptr_2->next;
                ptr_2->next = nullptr;
            }
            curr = next;
        }

        //connect the two sublist.
        ptr_1->next = dummyEqualOrGreater->next;
        return dummyLessThan->next;
        


    }
};