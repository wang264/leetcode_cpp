#include <math.h>
#include <vector>
#include <algorithm>

using std::vector;

// good solution
class Solution {
public:

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // [[1,2],[3,5],[6,7],[8,10],[12,16]]
        // [4,8]
        vector<vector<int>> rslt;

        int n = intervals.size();
        int i =0;
        // case 1: end point of existing intervals smaller than start of new interval, 
        // no chance for overlap   [1,2]
        while (i<n && intervals[i][1] < newInterval[0]) {
            rslt.push_back(intervals[i]);
            i++;
        }

        // case 2: merging intervals for overlapping case.
        // when fall into this case, the current intervals's end >= than new interval starting point.
        while (i<n && newInterval[1]>=intervals[i][0]) {
            newInterval[0] = std::min(newInterval[0], intervals[i][0]);
            newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            i++;
        }
        rslt.push_back(newInterval);

        //case 3: no overlapping after new interval being merged.
        while (i<n) {
            rslt.push_back(intervals[i]);
            i++;
        }
        return rslt;
    }
};

// offical solution but not that good. 
class Solution2 {
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
