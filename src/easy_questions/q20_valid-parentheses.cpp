#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>

using std::string;

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        std::unordered_map<char, char> map = { {')', '('}, {']', '['}, {'}', '{'}};
        std::unordered_set<char> set = {'(', '{', '['};
        for (const char& c: s) {
            if (set.count(c)>0) {
                stack.push(c);
            }
            else {
                if (stack.empty()) {
                    return false;
                } else if (stack.top() == map[c]) {
                    stack.pop();
                } else { 
                    return false;
                }

            }
        }
        return stack.empty();
    }
};