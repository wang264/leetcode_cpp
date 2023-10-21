#include <string>
#include<vector>

using std::vector;
using std::string;


class Solution {
public:
    // LCP = longestCommonPrefix
    // b/c  LCP(S1..Sn) = LCP(LCP(LCP(S1,S2), S3), ...Sn)

    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){return "";}
        if(strs.size() == 1){
            return strs[0];
        }
        string prefix = strs[0];

        for(string& s : strs){
            while(s.find(prefix)!=0){
                prefix = prefix.substr(0, prefix.length()-1);
            }
        }
        return prefix;
        
    }
};

int main(){return 0;}

// g++ -std=c++20 -o q14_longest-common-prefix q14_longest-common-prefix.cpp
