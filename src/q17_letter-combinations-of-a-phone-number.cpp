#include <unordered_map>
#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
    std::unordered_map<char, string> my_map = { {'2', "abc"},
                                                {'3', "def"},
                                                {'4', "ghi"},
                                                {'5', "jkl"},
                                                {'6', "mno"},
                                                {'7', "pqrs"},
                                                {'8', "tuv"},
                                                {'9', "wxyz"}
                                              };

    vector<string> letterCombinations(string digits) {
      if (digits.empty()) {
        return vector<string>();
      }
      vector<string> rslt;
      vector<char> path;
      dfs(digits, 0, path, rslt);
      return rslt;  
    }

    void dfs(string digits, int idx, vector<char>& path, vector<string>& rslt){
      if (idx == digits.size()) {
        string s(path.begin(), path.end());
        rslt.emplace_back(s);
        return;
      }

      for(const auto& c: my_map[digits[idx]]) {
        path.push_back(c);
        idx++;
        dfs(digits, idx, path, rslt);
        idx--;
        path.pop_back();
      }

    } 
};