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

class Solution2 {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        auto greater = [](int a, int b) {
            if (a>b) {
                return true;
            } else {
                return false;
            }
        };
        // pq is by default a maxheap, and use the function std::less
        // for minheadp we need to construct function std::greater.
        std::priority_queue<int, vector<int>, decltype(greater)> pq;
        
        // sort by start time from small to large
        std::sort(intervals.begin(), intervals.end());
        int max_rooms = 1;
        int num_rooms = 1;

        pq.push(intervals[0][1]);  // push first meetings end time.
        for (int i=1; i<intervals.size(); i++) {

            // if next meetings start time is less than the minimum end time of the current 
            // on going meetings.(minimum end time is the time that is on top of the minqueue)
            if (intervals[i][0] < pq.top()) {
                pq.push(intervals[i][1]);
                num_rooms++;
            } else {
                while(!pq.empty() && pq.top() <= intervals[i][0]) {
                    pq.pop();
                    num_rooms--;
                }
                pq.push(intervals[i][1]);
                num_rooms++;
            }
            max_rooms = num_rooms > max_rooms ? num_rooms : max_rooms;
        }
        return max_rooms;
    }
};

// intervals =[[13,15],[1,13]]
// meeting_rooms = 1

