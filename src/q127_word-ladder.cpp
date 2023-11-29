#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <vector>

using std::string;
using std::vector;


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::unordered_set<string> wordDict(wordList.begin(), wordList.end());
        std::unordered_set<string> visited;
        std::queue<string> q;

        q.push(beginWord);
        visited.insert(beginWord);
        int distance = 1;

        while(!q.empty()) {
            int n = q.size();
            for (int i=0; i<n; i++) {
                string word = q.front();
                q.pop();
                if (word == endWord) {
                    return distance;
                }

                for (int j =0; j<word.size(); j++) {
                    char c = word[j];
                    for (int k=0; k<26; k++) {
                        word[j] = 'a' + k;
                        if (wordDict.count(word)==1 && visited.count(word)==0) {
                            q.push(word);
                            visited.insert(word);
                        }
                    }
                    word[j] = c; //set it back.
                }
            }
            distance++;
        }
        return 0;

    }
};

class Solution2 {
public:
    int length;
    std::unordered_map<string, std::unordered_set<string>> all_combo_map;

    std::pair<int, bool> visitWordNode(std::queue<string>& q, std::unordered_map<string, int>& visited,  std::unordered_map<string, int>& others_visited) {
        int n = q.size();
        for (int i=0; i<n; i++) {
            string current_word = q.front();
            q.pop();
            for (int j=0; j<length; j++) {
                // Intermediate words for current word
                string intermediate_word = current_word;
                intermediate_word[j] = '*';
                // Next states are all the words which share the same intermediate state.
                if (all_combo_map.count(intermediate_word)) {
                    for (const auto& word: all_combo_map[intermediate_word]) {
                        // If the intermediate state/word has already been visited from the
                        // other parallel traversal this means we have found the answer.
                        if (others_visited.count(word)) {
                            int steps = visited[current_word] + others_visited[word];
                            return std::make_pair(steps, true);
                        }
                        if (!visited.count(word)) {
                            // save the level as the value of the map, to save number of hops
                            visited[word] = visited[current_word] + 1;
                            q.push(word);
                        }
                    }
                }
            }
        }
        return std::make_pair(-1, false);
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (std::find(wordList.begin(), wordList.end(), endWord)==wordList.end()) {
            return 0;
        }    
        // Since all words are of the same length.
        length = beginWord.size();

        for (const auto& word: wordList) {
            for (int i=0; i<length; i++) {
                string temp_word = word;
                temp_word[i] = '*';
                all_combo_map[temp_word].insert(word);
            }
        }
        // queues for bi directional BFS
        std::queue<string> queue_begin; //BFS starting from begin word
        queue_begin.push(beginWord);
        std::queue<string> queue_end; //BFS starting from end word
        queue_end.push(endWord);

        // visited to make sure we don't repeat processing same word
        std::unordered_map<string, int> visited_begin;
        visited_begin[beginWord]=1;
        std::unordered_map<string, int> visited_end;
        visited_end[endWord]=1;
        std::pair<int, bool> answer;

        while (!queue_begin.empty() && !queue_end.empty()) {
            // Progress forward one step from the shorter queue
            if (queue_begin.size() <= queue_end.size()) {
                answer = visitWordNode(queue_begin, visited_begin, visited_end);
            } else {
                answer = visitWordNode(queue_end, visited_end, visited_begin);
            }
            if (answer.second) {
                return answer.first;
            }
        }
    //no answer
    return 0;
    }
};