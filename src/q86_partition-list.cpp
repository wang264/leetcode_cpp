
#include "../src/helper/listnode.h"
#include "iostream"

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode less_dummy = ListNode(-1) ;
        ListNode great_eq_dummy = ListNode(-1);
        
        ListNode* curr_ptr = head;
        while (curr_ptr!= nullptr)
        {
            if (curr_ptr->val < x){
                ListNode* temp = curr_ptr->next;
                curr_ptr->next = less_dummy.next;
                less_dummy.next = curr_ptr;
                curr_ptr = temp;
            }
            else{
                ListNode* temp = curr_ptr->next;
                curr_ptr->next = great_eq_dummy.next;
                great_eq_dummy.next = curr_ptr;
                curr_ptr = temp;
            }
        }
        //find the tail of less listnode;
        ListNode* less_tail = &less_dummy;
        while (less_tail->next != nullptr)
        {
            less_tail = less_tail->next;
        }
        less_tail->next = great_eq_dummy.next;
        
        return less_dummy.next;
    }

    void runtest()
    {   std::vector<int> vec = {1, 4, 3, 2, 5, 2};
        ListNode *head = ListNode::buildList(vec);
        ListNode *result = partition(head, 3);
        ListNode::print(head);
        ListNode::print(result);
    }
};

int main()
{
    auto solution = Solution();
    solution.runtest();
    return 0;
}