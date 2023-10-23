#include<math.h>
#include<vector>

using std::vector;


class Solution {
    // two pointer. 
    // Now if the left line is shorter than the right line, then moving the right line towards
    // left would only decrease the volume, so all the elements left to (1,6) on the first row
    // have smaller volume.
    // water_volumn = distance * min(hieght_left, height_right) = distance * height_left 
    // since height_left < height_right, even if the new height_right is very large, since, 
    // min(hieght_left, new_height_right) = height_left, so volumn will decrease.
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() -1;

        int max_volumn = 0;
        while (left < right) {
            int distance = right - left;
            max_volumn = std::max(max_volumn, distance * std::min(height[left], height[right]));
            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }

        }
        return max_volumn;
        
    }
};

int main() {
    return 0;
}

// g++ -std=c++11 -o q11_container-with-most-water q11_container-with-most-water.cpp