#include <vector>
#include <queue>


using std::vector;

//Approach 2: use priority queue

//Approach 2: Chronological Ordering
// process the start time and end time seperately, but in chronological order.
class Solution2 {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        
        vector<int> start_time;
        vector<int> end_time;
        for (const auto& interval: intervals) {
            start_time.push_back(interval[0]);
            end_time.push_back(interval[1]);
        }
        std::sort(start_time.begin(), start_time.end());
        std::sort(end_time.begin(), end_time.end());

        int curr_rooms = 0;
        int max_rooms = 0;
        int start = 0;
        int end = 0;

        while(end < intervals.size()) {
            if (start<intervals.size() && start_time[start] < end_time[end]) {
                curr_rooms++;
                max_rooms = curr_rooms > max_rooms ? curr_rooms : max_rooms;
                start++;
            } else {
                curr_rooms--;
                end++;
            }
        }
        return max_rooms;

    }
};