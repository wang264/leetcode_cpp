#include <algorithm>
#include <vector>

using std::vector;

class Solution {
    //That means that one could always track the end of the current balloon,
    // and ignore all the balloons which end before it. Once the current balloon
    // is ended (= the next balloon starts after the current balloon),
    // one has to increase the number of arrows by one and start to track
    // the end of the next balloon.

    //Let's sort the balloons by the end coordinate, and then check them one by one. 
    // if the current ballon is [a, b], then all other ballons [c,d] such that c<=b could pop 
    // by using the same arrow.
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0){ return 0;}

        std::sort(points.begin(), points.end(), 
            [](const vector<int> &o1, const vector<int>& o2) {
                return (o1[1]<o2[1]); // if o1[1]<o2[1], o1 will apear in front of o2
            });
        
        int arrows = 1;
        int xStart, xEnd, prevEnd = points[0][1];
        for (const auto& point: points) {
            xStart = point[0];
            xEnd = point[1];
            // if the current balloon starts after the end of another one,
            // one needs one more arrow
            if (prevEnd < xStart) {
                arrows++;
                prevEnd = xEnd;
            }
        }
        return arrows;
    }
};