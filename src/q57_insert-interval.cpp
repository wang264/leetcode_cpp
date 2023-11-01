#include <math.h>
#include <vector>
#include <algorithm>

using std::vector;


class Solution {
public:

    // return true if the interval a, b overlap.
    bool doesIntervalOverlap(vector<int>& a, vector<int>& b) {
        return (std::min(a[1], b[1]) - std::max(a[0], b[0])) >=0;
    }

     // Insert the interval newInterval, into the list interval keeping the sorting order intact.
    void insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int index = std::upper_bound(intervals.begin(), intervals.end(), newInterval) - intervals.begin();
        if (index != intervals.size()) {
            intervals.insert(intervals.begin()+index, newInterval);
        }
        else {
            intervals.push_back(newInterval);
        }
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Insert the interval first before merge processing.
        insertInterval(intervals, newInterval);

        vector<vector<int>> rslt;
        for (int i=0; i<intervals.size(); i++) {
            // if rslt is empty, or we have no overlap.
            if (rslt.empty() || rslt.back()[1]< intervals[i][0]) {
                rslt.push_back(intervals[i]); 
            }
            else {
                rslt.back()[1] = std::max(rslt.back()[1], intervals[i][1]);
            }
        }
        return rslt;

    }
};

int main() {
    return 0;
}


// g++ -std=c++11 -o q57_insert-interval q57_insert-interval.cpp
