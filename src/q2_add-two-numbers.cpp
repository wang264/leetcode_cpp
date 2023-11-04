
// Definition for singly-linked list.
struct ListNode {
    public:
      int val;
      ListNode *next;

      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        int carry=0;
        ListNode* prev = dummy;

        while(l1!=nullptr || l2!=nullptr || carry!=0) {
            int l1_val = l1==nullptr ? 0 : l1->val;
            int l2_val = l2==nullptr ? 0 : l2->val;
            int num = l1_val + l2_val + carry;
            carry = 0;
            if (num>=10) {
                carry =1;
                num = num%10;
            }
            ListNode* node = new ListNode(num);
            prev->next = node;
            prev = node;
            l1 = l1 ? l1->next: nullptr;
            l2 = l2 ? l2->next: nullptr;
        }

        return dummy->next;
    }
};