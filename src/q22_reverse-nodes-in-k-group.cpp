
// Definition for singly-linked list.
#include<listnode.h>

//iterative solution
class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head, int k) {
        // rever k nodes of the given linked list. (assume that the list contain at least k nodes)
        ListNode* prev = nullptr;
        ListNode* curr = head;

        for(int i=0; i<k; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ptr = head;
        ListNode* ktail = nullptr;

        ListNode* new_head = nullptr; // head of the final, modified linked list

        while (ptr) {
            int count = 0;
            ptr = head;
        
            //find the head of the next set of k nodes;
            while (ptr && count<k) {
                ptr = ptr->next;
                count++;
            }

            // if we count k nodes, reverse them
            if (count == k) {
                ListNode* revHead = reverseLinkedList(head, k);

                // new_head is the head of the final linked list
                if (!new_head) {
                    new_head = revHead;
                }
                //ktail is the tail of the previous block of reversed k nodes
                if (ktail) {
                    ktail->next = revHead;
                }
                ktail = head;
                head = ptr;
            }
        }
        // attach the final, possibly un-reversed portion
        if (ktail) {
            ktail->next = head;
        }
        
        return  new_head ? new_head : head;
    

    }
};

//recursive solution
class Solution2 {
public:
    ListNode* reverseLinkedList(ListNode* head, int k) {
        // rever k nodes of the given linked list. (assume that the list contain at least k nodes)
        ListNode* prev = nullptr;
        ListNode* curr = head;

        for(int i=0; i<k; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int count =0;
        ListNode* curr = head;

        //see if we have at least k nodes;
        while(curr!=nullptr && count<k) {
            curr = curr->next;
            count++;
        }

        //If we have k nodes, then we reverse them.
        if (count==k) {
            //reverse the first k nodes of the list and got the reversed head;
            ListNode* reversedHead = reverseLinkedList(head, k);
            // Now recurse on the remaining linked list. Since
            // our recursion returns the head of the overall processed
            // list, we use that and the "original" head of the "k" nodes
            // to re-wire the connections.
            head->next = reverseKGroup(curr, k);
            return reversedHead;
        }
        return head;
    

    }
};