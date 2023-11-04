/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* l = nullptr;
        ListNode* left_ptr = head;
        for(int i=0; i<left-1; i++) {
            l = left_ptr;
            left_ptr = left_ptr->next;
        }
        
        ListNode* right_ptr = head;
        for(int i=0; i<right-1; i++) {
            right_ptr = right_ptr->next;
        }
        ListNode* r = right_ptr->next;
        
        right_ptr->next = nullptr;
        ListNode* reversed_head = reverseList(left_ptr);
        if (l) {
            l->next = reversed_head;
        }
        left_ptr->next = r;

        if (left==1) {
            return right_ptr; 
        } else {
            return head;
        }
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;        
    }

};

// head = [3,5] , left=1, right-2;