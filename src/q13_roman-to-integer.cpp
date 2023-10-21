#include<unordered_map>
#include<iostream>

class Solution {
public:
    int romanToInt(std::string s) {

        int result = 0;
        std::unordered_map<char, int> mymap{
            {'I', 1}, 
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        for(int i=0; i<s.length(); i++){
            // this case would be IV, CM, XL....
            if (mymap[s[i]] < mymap[s[i+1]]){
                result -= mymap[s[i]];
            }
            else{
                result += mymap[s[i]];
            }
        }

        return result;

    }
};