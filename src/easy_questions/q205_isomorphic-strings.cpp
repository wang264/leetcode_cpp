#include<string>
#include<unordered_map>

using std::string;
using std::unordered_map;


class Solution {
    // need two way mapping. think about this case:
    // s = badc
    // t = baba
public:
    bool isIsomorphic(string s, string t) {

        if (s.size()!=t.size()) {
            return false;
        }
        unordered_map<char, char> map_s_2_t;
        unordered_map<char, char> map_t_2_s;

        for (int i=0; i<s.size(); i++) {
            //if s does not have a maaping.
            if (map_s_2_t.count(s[i])==0) {
                map_s_2_t[s[i]] = t[i];
                if (map_t_2_s.count(t[i])==0) {
                    map_t_2_s[t[i]] = s[i];
                }
                else {
                    return false;
                }
            }
            else {
                if (map_s_2_t[s[i]] != t[i]) {
                    return false;
                }
            }
        }

        return true;
    }

};

// ac
// bb