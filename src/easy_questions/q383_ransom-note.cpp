#include<unordered_map>
#include<string>

using std::string;
using std::unordered_map;


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;

        for (const char& c: magazine) {
            map[c]++;
        }

        for (const char& c: ransomNote) {
            if(map.count(c)<=0) {
                return false;
            }
            else {
                map[c]--;
                if (map[c]==0) {
                    map.erase(c);
                }
            }
        }
        return true;
    }
};