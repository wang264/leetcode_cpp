#include<string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int n = s.size();
        int count = 0;
        // found index of last valid letter
        int idx = n-1;
        while(s[idx] == ' '){
            idx--;
        }

        while(idx>=0 && s[idx] != ' '){
            idx--;
            count++;
        }


        return count;
    }
};