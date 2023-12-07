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
#include <listnode.h>

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) {
          return head;
        }
        ListNode* mid = getMidAndSplit(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return mergeLists(left, right);
    }

    ListNode* mergeLists(ListNode* list1, ListNode* list2) {
      ListNode dummy(0);
      ListNode* ptr = &dummy;
      while (list1 && list2) {
        if (list1->val < list2->val) {
          ptr->next = list1;
          list1 = list1->next;
        } else {
          ptr->next = list2;
          list2 = list2->next;
        }
        ptr = ptr->next;
      }
      if (list1) {
        ptr->next = list1;
      } else {
        ptr->next = list2;
      }
      return dummy.next;
    }

    ListNode* getMidAndSplit(ListNode* head) {
      //  d   [1     0]
      //       |
      //                 |
      ListNode dummy = ListNode(0);
      dummy.next = head;
      ListNode* mid_prev = &dummy; 
      ListNode* fast = head;
      while (fast && fast->next) {
        mid_prev = mid_prev->next;
        fast = fast->next->next;
      }
      ListNode* mid = mid_prev->next;
      mid_prev->next = nullptr;
      return mid;
    }
};