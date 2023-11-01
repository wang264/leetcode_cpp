#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using std::string;

class Solution {
public:
    string simplifyPath(string path) {
        // Initialize a stack
        std::stack<string> stack;
        std::istringstream ss(path);
        std::string token;

        // Split the input string on "/" as the delimiter
        // and process each portion one by one
        while(std::getline(ss, token, '/')) {
            // If the current component is a "..", then we pop an entry from the stack if it's non-empty
            if (token == "..") {
                if (!stack.empty()) {
                    stack.pop();
                }
            // A no-op for a "." or an empty string
            } else if (token == "." || token.empty()) {
                continue;
            } else {
                //a legitimate directory name, so we add it to our stack
                stack.push(token);
            }
        }

        // Stich together all the directory names together
        string rslt;
        std::vector<string> temp;
        while (!stack.empty()) {
            temp.push_back(stack.top());
            stack.pop();
        }
        std::reverse(temp.begin(), temp.end());
        for (auto dir: temp) {
            rslt.append("/");
            rslt.append(dir);
        }

        return rslt.size()>0 ? rslt : "/";
    }
};

int main() {
    return 0;
}


// g++ -std=c++11 -o q71_simplify-path q71_simplify-path.cpp