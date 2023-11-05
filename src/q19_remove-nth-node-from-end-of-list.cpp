
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;
        // advance first pointer so that the gap of first and second is n nodes apart. 
        // if we do this when first point to null(1 pass the end), second's next will be the
        // pointer we want to delete
        for (int i=0; i<n+1;i++) {
            first = first->next;
        }
        // maintain the gap and move first to the end;
        while (first) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummy->next;
    }
};