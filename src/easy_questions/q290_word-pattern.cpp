#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>

using std::string;
using std::unordered_map;
using std::vector;
using std::istringstream;


class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> map_c2w;
        unordered_map<string, char> map_w2c;
        
        vector<string> words;

        string word;
        istringstream my_stream(s);
        while (my_stream>>word) {
            words.push_back(word);
        }
        
        if (pattern.size()!=words.size()) {return false;}

        for (int i=0; i<pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];

            if (map_c2w.count(c)==0) {
                if (map_w2c.count(w)==0) {
                    map_c2w[c]=w;
                    map_w2c[w]=c;
                }
                else {
                    return false;
                }
            }
            else {
                if (map_c2w[c]!=w) {return false;}
            }
        }

        return true;
        
        
    }
};