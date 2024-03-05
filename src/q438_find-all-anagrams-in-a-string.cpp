#include <vector>
#include <string>
#include <unordered_map>

using std::string;
using std::vector;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int chars_need = 0;
        int chars_found = 0;
        int left = 0;
        int right = 0;
        int n = s.size();
        std::vector<int> rslt;
        std::unordered_map<char, int> my_map;
        std::unordered_map<char, int> target_map;
        for (const auto& c: p) {
            target_map[c]++;
        }
        chars_need = target_map.size();
        // 0 1 2 3 4 5 6 7 8 9
        // c b a e b a b a c d
        //   |
        //         |
        // {c:0, b:1, a:1, e:1}
        //chars_found=2
        while (right<n) {
            if (right>=p.size()) {
                char c_old =s[left];
                if (my_map[c_old]==target_map[c_old]) {
                    chars_found--;
                }
                my_map[c_old]--;
                left++; //start of the current window, and also point to the location that need to be delete in the next round, 
            }
            // "right" point to the new chars.
            char c_new = s[right];
            my_map[c_new]++;
            if (my_map[c_new]==target_map[c_new]) {
                chars_found++;
            }
            if (chars_found == chars_need) {
                rslt.push_back(left);
            }
            right++;
        }
        return rslt;
    }
};