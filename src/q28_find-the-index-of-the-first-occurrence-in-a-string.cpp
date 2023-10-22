#include<string>

using std::string;

class Solution {
public:
    int strStr(string haystack, string needle) {
    int n = haystack.size();
    int m = needle.size();

    for (int windowStart=0; windowStart<= n-m; windowStart++) {
        for (int i =0; i<m;i++){
            if (needle[i]!= haystack[windowStart+i]) {
                break;
            }
            if (i == m-1) {
                return windowStart;
            }
        }
    }

    return -1;
        
    }
};