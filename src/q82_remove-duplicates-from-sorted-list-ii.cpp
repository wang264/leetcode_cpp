#include<listnode.h>


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;
        
        while (curr && curr->next) {
            bool delete_node = false;
            // if it's a beginning of duplicates sublist skip all duplicates
            while(curr && curr->next && curr->val == curr->next->val) {
                curr = curr->next;
                delete_node = true;
            }

            if (delete_node) {
                // skip all duplicates
                prev->next = curr->next;
            } else {
                // otherwise, move predecessor
                prev = curr;
            }
            // move forward
            curr=curr->next;

        }
        return dummy->next;

    }
};

int main() {
    return 0;
}

//g++ -std=c++11 -o q82_remove-duplicates-from-sorted-list-ii q82_remove-duplicates-from-sorted-list-ii.cpp -I ./