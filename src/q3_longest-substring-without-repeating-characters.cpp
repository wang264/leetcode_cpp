#include<unordered_map>
#include<string>
#include<math.h>

using std::max;
using std::string;
using std::unordered_map;

class Solution {
// sliding window.
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> my_map;
        int left = 0;
        int right = 0;

        int rslt = 0;
        while(right < s.size()) {
            char c = s[right];
            my_map[c] = my_map[c]+1; // in C++ if 'c' is not yet in the map. my_map[c] will return 0 and create an entry in the map and set my_map[c] = 0; 
            while (my_map[c] > 1) { //we start to see duplicate
                char left_char = s[left];
                my_map[left_char]--;
                left++;
            }
            // there is no duplicate
            rslt = max(rslt, right - left +1);
            right++;  // we found the longest valid subarray ending at right, so we increase right by 1.  
            
        }
        return rslt;

    }
};