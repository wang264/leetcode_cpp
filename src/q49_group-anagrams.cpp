#include <vector>
#include <string>
#include <unordered_map>

using std::unordered_map;
using std::string;
using std::vector;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // key is the string(sorted), value is the vector of string.
        unordered_map<string, vector<string>> mymap; 

        for (const string& str: strs) {
            string s = str;
            std::sort(s.begin(), s.end());
            mymap[s].push_back(str);
            
        }

        vector<vector<string>> rslt;

        for (auto i: mymap) {
            rslt.push_back(std::move(i.second));
        }
        return rslt;
        
    }
};