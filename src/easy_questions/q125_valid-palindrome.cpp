#include<string>
#include <locale>         // std::locale, std::isalnum, std::tolower

using std::string;

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0;
        int right = n-1;

        while(left <=right){
            if (!std::isalnum(s[left])) {
                left++;
            }
            else if (!std::isalnum(s[right])) {
                right--;
            }
            else {
                if (std::tolower(s[left]) == std::tolower(s[right])) {
                    left++;
                    right--;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};


int main(int argc, char *argv[])
{
    return 0;
}

// g++ -std=c++11 -o q125_valid-palindrome q125_valid-palindrome.cpp