#include<string>
#include<vector>

using std::vector;
using std::string;

class TrieNode {
public:
    string word;
    TrieNode* children[26];

    TrieNode(): word("") {
        for(auto& child: children) {
            child = nullptr;
        }
    }
};

class Solution {
    vector<int> xDirections = {0,0, 1, -1};
    vector<int> yDirections = {1, -1, 0, 0};

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        //build the Tire
        TrieNode* trie = buildTrie(words);
        vector<string> rslt;
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                dfs(board, i, j, trie, rslt);
            }
        }
        return rslt;

    }
    /** Inserts a word into the trie. */
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const auto& word: words) {
            TrieNode* curr = root;
            for (const char& c: word) {
                int i = c - 'a';
                if (curr->children[i] == nullptr) {
                    curr->children[i] = new TrieNode();
                }
                curr = curr->children[i];
            }
            curr->word = word;
        }
        return root;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string> &rslt) {
        char c = board[i][j];
        // we use '#' to represent we already visit this cell
        int idx = c - 'a';
        if (c == '#' || node->children[idx]==nullptr) {
            return;
        }
        node = node->children[idx];
        if (!node->word.empty()) {
            rslt.push_back(node->word);
            node->word = ""; //prevent same answer to get added again.
        }
        
        board[i][j] = '#'; //add the the visited matrix;
        for (int k=0; k<4; k++) {
            int dx = xDirections[k];
            int dy = yDirections[k];
            int new_x = i + dx;
            int new_y = j + dy;
            if (new_x>=0 && new_x<board.size() && new_y>=0 && new_y<board[0].size()) {
                dfs(board, new_x, new_y, node, rslt);
            }
        }
        board[i][j] = c; //set it back.

    }
};