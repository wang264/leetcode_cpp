#include <deque>
#include <vector>

using std::vector;

class DecreasingMonotonicQueue {
    public:
        std::deque<int> dq;

        void pop_front() {
            dq.pop_front();
        }
        // whenever we add new elements, we want to the elements that are smaller than that number.
        // since for each new element K enter into the interval, for all other future interval, numbers
        // that smaller than K will never become maximum of the intervals. (K will always be in that intervals and get kick out later)
        
        void push_back(int& num) {
            while (!dq.empty() && dq[dq.size()-1]<num) {
                dq.pop_back();
            }
            dq.push_back(num);
        }
        int max() {
            return dq[0];
        }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        DecreasingMonotonicQueue q;
        vector<int> rslt;
        for (int i=0; i<nums.size(); i++) {
            q.push_back(nums[i]);
            // have enough element in the window
            if (i >= k - 1) {
                rslt.push_back(q.max());
                // # if the element we need to kick out is the max.
                if (nums[i - k + 1] == q.max()) {
                    q.pop_front();
                }
            }

        }
        return rslt;
    }
};