#include <string>

using std::string;
class Solution {
public:
    string addBinary(string a, string b) {
        std::string answer;
        int carry = 0;
        int i = a.size()-1;
        int j = b.size()-1; 

        while(i>=0 || j>=0 || carry) {
            if (i>=0) {
                carry +=a[i]-'0';
                i--;
            }
            if (j>=0) {
                carry +=b[j]-'0';
                j--;
            }
            answer += carry%2 + '0';
            carry /=2;
        }
        std::reverse(answer.begin(), answer.end());
        return answer;
    }
};