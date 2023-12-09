#include <vector>
#include <queue>
#include <listnode.h>

using std::vector;


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto greater = [](ListNode* left, ListNode* right) {
            return left->val > right->val;
        };  // similar to std::greater_than<T>
        
        // by default the queue is max queue, we make it a min queue. 
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(greater)> pq(greater);

        ListNode dummy = ListNode(0);
        ListNode* curr = &dummy;
        for (ListNode* node: lists) {
            if (node) {
                pq.push(node);
            }
        }

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            curr->next = node;
            node = node->next;
            if (node) {
                pq.push(node);
            }
            curr = curr->next;
        }


        return dummy.next;

    }
};