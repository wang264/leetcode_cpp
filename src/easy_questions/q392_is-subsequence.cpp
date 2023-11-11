#include<string>

using std::string;

class Solution {

public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;
        
        int idx_s = 0; 
        for(int i=0; i<t.size(); i++) {
            if (t[i] == s[idx_s]) {
                if (idx_s == s.size()-1) {
                    return true;
                }
                else {
                    idx_s++;
                }

            }
        }
        return false;
        
    }
};