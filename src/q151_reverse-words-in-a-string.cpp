#include<string>
#include<utility>  //std::reverse

using std::string;


class Solution {
public:
    string reverseWords(string s) {
        //reverse the whole world
        int n = s.size();
        std::reverse(s.begin(), s.end());
        // int first_letter_idx = 0;
        // for(int i = 0;i<n;i++){
        //     if(s[i] != ' '){
        //         first_letter_idx = i;
        //         break;
        //     }
        // }
        
        //since we need to trim the spaces, this is to track to location that we are ok to swap.
        int idx =0; 
        for (int start = 0; start<n; start++){
            if (s[start]== ' ') continue;
            
            //after finish previous iteration, index will point to left of the last character of the previous word. so we insert an space here. 
            if (idx != 0) {
                s[idx] = ' ';
                idx++;
            }
            //from the start of the word, to the end of the word. we write each char of this word to location idx. 
            int end = start;
            while(end<n && s[end]!=' '){
                s[idx] = s[end];
                idx++;
                end++;
            }
            //reverse the whole world
            //reverse(s.begin() + start, s.begin() + end);
             reverse(s.begin() + idx - (end - start), s.begin() + idx);
             
            // move to the next world
            start = end;
        }
        
        // s = s.substr(first_letter_idx, end - first_letter_idx );
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};