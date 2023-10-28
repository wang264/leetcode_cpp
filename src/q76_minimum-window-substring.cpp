#include<string>
#include<unordered_map>

using std::string;
using std::unordered_map;


class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        int right = 0;

        unordered_map<char,int> target_map;
        for (const char& c:t) {
            target_map[c]++;
        }
        unordered_map<char, int> my_map;
        int chars_found = 0; 
        int chars_needed = target_map.size();

        int answer_len = INT_MAX;
        string answer = "";

        while (right<s.size()) {
            // add one chars from right to the window
            char c = s[right];
            my_map[c]++;
            // if frequecy of the current add is equal to the frequency need
            if (target_map.count(c)>0 && (my_map[c] == target_map[c])) {
                chars_found++;
            }
            // if we find the valid substring, we try to contract the window by moving left pointer toward
            // the end to make the window become invalid
            while (left<=right && chars_found == chars_needed) {
                char c_left = s[left];
                // try update the answer
                if (right-left+1 < answer_len) {
                    answer_len = right-left+1;
                    answer = s.substr(left, right-left+1);
                }
                // the char at the position pointed by 'left' is no longer in the window
                my_map[c_left]-=1;
                if (target_map.count(c_left)>0 && my_map[c_left]<target_map[c_left]) {
                    chars_found-=1;
                }
                left+=1;
            }
            // keep expending the window
            right+=1;
        }



        return (answer_len == INT_MAX) ? "" : answer;

        
    }
};


//ABC
// |
// AdddAddBCddCBdAa
//         |  

