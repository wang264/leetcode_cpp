#include<unordered_map>
#include<string>
#include<vector>

using std::vector;
using std::string;
using std::unordered_map;

class Solution {
public:

    void sliding_window(int left, const unordered_map<string, int>& word_count, vector<int>& answer, const string& s, const vector<string>& words) {
        int n = s.size();
        int k = words.size();
        int word_length = words[0].size();
        int substring_size = word_length * k;
        unordered_map<string, int> words_found;
        int words_used = 0;
        bool excess_word = false;

        // Do the same iteration pattern as the previous approach - iterate
        // word_length at a time, and at each iteration we focus on one word
        for (int right = left; right<n; right+=word_length) {
            if (right + word_length > n) {
                break;
            }
            string sub = s.substr(right, word_length);
            if (word_count.find(sub) == word_count.end()) {
                // Mismatched word - reset the window
                words_found.clear();
                words_used = 0;
                excess_word = false;
                left = right + word_length; // retry at the next index
            }
            else {
                // If we reached max window size or have an excess word
                while (right - left == substring_size || excess_word) {
                    // Move the left bound over continously
                    string leftmost_word = s.substr(left, word_length);
                    left += word_length;
                    words_found[leftmost_word] -=1;

                    if (words_found[leftmost_word] == word_count.find(leftmost_word)->second) {
                        // This word was the excess word
                        excess_word = false;
                    }
                    else {
                        // Otherwise we actually needed it
                        words_used -=1;
                    }
                }
                // Keep track of how many times this word occurs in the window
                words_found[sub]+=1;
                if (words_found[sub] <= word_count.find(sub)->second) {
                    words_used +=1;
                }
                else {
                    //found too many instance of that word.
                    excess_word = true;
                }

                if (words_used == k && !excess_word) {
                    // found a valid substring
                    answer.push_back(left);
                }
            }
        }
    }

    
    vector<int> findSubstring(string s, vector<string>& words) {
        int word_length = words[0].size();
        unordered_map<string, int> word_count;
        for (const auto& word: words) {
            word_count[word]++;
        }
        vector<int> answer;
        for (int i =0; i<word_length; i++) {
            sliding_window(i, word_count, answer, s, words);
        }
        return answer;
    }
};