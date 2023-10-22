#include<vector>
#include<string>

using std::string;
using std::vector;


class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> rslt;
        int idx=0; 
        while (idx < words.size()) {
            auto wordsCurrLine = getWords(words, idx, maxWidth);
            idx += wordsCurrLine.size();

            if (idx>= words.size()) {  // this means this line is the last line
                rslt.push_back(generateLine(wordsCurrLine, maxWidth, true));
            }
            else{
                rslt.push_back(generateLine(wordsCurrLine, maxWidth, false));
            }
        }
        return rslt;
    }

    vector<string> getWords(vector<string>& words, int startIdx, int maxWidth) {
        int char_counts = 0;
        vector<string> rslt;
        for (int i =startIdx; i<words.size(); i++) {
            // check if we could include this word;
            if (char_counts + words[i].size() <= maxWidth) {
                rslt.push_back(words[i]);
                char_counts +=words[i].size();
                char_counts++; //pad a space after each word;
            }
            else {
                break;
            }
        }
        return rslt;
    }

    string generateLine(vector<string>& words, int maxWidth, bool force_left) {
        if (words.size() == 1) {
            int space_count = maxWidth - words[0].size();
            string rslt;
            rslt += words[0];
            for (int i=0; i<space_count; i++){
                rslt+=" ";
            }
            return rslt;
        }
        if (force_left) {
            int char_count = 0;
            string rslt;
            for (string word: words) {
                char_count += word.size();
                rslt += word;
                // if we all to insert a space
                if (char_count < maxWidth) {
                    char_count++;
                    rslt += " ";
                }
            }
            // calculate how many need to fill by space
            int num_space = maxWidth - char_count;
            for (int i =0; i<num_space; i++) {
                rslt += " ";
            }
            return rslt;
        }

        // normal right justification
        int char_counts = 0;
        for (const string& word: words) {
            char_counts += word.size();
        }
        // need to allocate (maxWidth - char_counts) space character into (words.size() - 1) slot;
        int k = (maxWidth - char_counts) / (words.size() - 1);  //number of space in between each word
        int remainder = (maxWidth - char_counts) % (words.size() - 1); //remainder.
        // in reality, since  If the number of spaces on a line does not divide evenly between words,
        // the empty slots on the left will be assigned more spaces than the slots on the right.
        // ===> so we need to give extra space the gaps from the left.
        string rslt;
        for (int i=0;i<words.size();i++){
            rslt+=words[i];
            if (i == words.size()-1) {
                break; //no space for last word;
            }

            // insert space;
            string spaces = string(k, ' ');
            rslt+=spaces;
            if (remainder>0) {
                rslt +=" ";
                remainder--;
            }
        }
        return rslt;

    }
};