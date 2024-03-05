#include <unordered_map>
#include <string>

using std::string;

class Solution {
public:
    int longestPalindrome(string s) {
        std::unordered_map<char, int> map;
        for (const auto& c : s) {
            map[c]++;
        }
        int rslt =0;
        bool odd_used = false; // allow 1 letter only once, for palindrom of odd length.
        for (auto iter = map.begin(); iter != map.end(); iter++) {
            if (iter->second % 2==0) {
                rslt+=iter->second;
            } else {
                if (odd_used) {
                    rslt+=iter->second-1;
                } else {
                    rslt+=iter->second;
                    odd_used=true;
                }
            }
        }
        return rslt;

        return rslt;
    }
};