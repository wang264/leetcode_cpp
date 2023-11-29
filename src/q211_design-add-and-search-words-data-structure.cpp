#include <string>

using std::string;

class TrieNode {

public:
    bool isWord;
    TrieNode* child[26];
    TrieNode() {
        isWord = false;
        for (auto& c: child) {
            c = nullptr;
        }
    }
};

class WordDictionary {
private:
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (const auto& c : word) {
            int i = c - 'a';
            if (!node->child[i]) {
                node->child[i] = new TrieNode();
            }
            node = node->child[i];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        return search_helper(word, root);
    }
    
    bool search_helper(string word, TrieNode* node) {
        for (int i=0; i<word.size(); i++) {
            int k = word[i] - 'a';
            // if we do not see a '.' then this is the normal search. 
            if (word[i] != '.') {
                if(node->child[k]) {
                    node = node->child[k];
                } else {
                    return false;
                }
            } else {
                // if we see a '.' we need to search all possible combinations.
                TrieNode* temp = node;
                for (int j = 0; j<26; j++) {
                    node = temp->child[j];
                    if (node) {
                        if (search_helper(word.substr(i+1), node)) {
                            return true;
                        }
                    }
                }
                return false;

            }
        }
        return node->isWord;

    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */