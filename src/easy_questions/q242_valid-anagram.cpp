#include<string>
#include<unordered_map>


using std::string;
using std::unordered_map;


class Solution {
public:
    bool isAnagram(string s, string t) {
      unordered_map<char, int> map;

      for (const char& c: s) {
          map[c]++;
      }  

      for (const char& c: t) {
          if (map.count(c)>0) {
            map[c]--;
            if (map[c]==0) {
                map.erase(c);
            }
          }
          else {
              return false;
          }
      }

      if (map.empty()) {
          return true;
      }
      else {
          return false;
      }
    }
};