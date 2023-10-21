#include<iostream>
#include <string>
#include <sstream>  //std::stringstream
#include<vector>
#include <utility> // std::pair


class Solution {
public:
    std::string intToRoman(int num) {
        std::vector<std::pair<int, std::string>> v = { {1000, "M"}, {900,"CM"}, {500, "D"}, {400, "CD"}, {100,"C"}, {90,"XC"}, {50, "L"}, {40,"XL"}, {10,"X"}, {9,"IX"}, {5,"V"}, {4,"IV"}, {1,"I"} };
        // Loop through each symbol, stopping if num becomes 0.
        std::stringstream ss;   
        for (int i=0; i<v.size() && num>0; i++){
            // Repeat while the current symbol still fits into num.
            while(v[i].first<=num){
                num -= v[i].first;
                ss<<v[i].second;
            }
        }
        return ss.str();
    }
};

int main(){
    return 0;
}

// g++ -std=c++17 -o q12_integer-to-roman q12_integer-to-roman.cpp