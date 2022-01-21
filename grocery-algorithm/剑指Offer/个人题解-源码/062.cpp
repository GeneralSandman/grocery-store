#include <iostream>
#include <vector>
#include <string.h>
#include <map>

using namespace std;

class Trie {
    class TrieNode {
    public:
        bool end;
        TrieNode* children[26];
        TrieNode() {
            end = false;
            memset(children, 0, sizeof(children));
        }
    };

    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for(auto ch:word) {
            if(node->children[ch-'a'] == nullptr) {
                node->children[ch-'a'] = new TrieNode();
            }
            node = node->children[ch-'a'];
        }

        node->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for(auto ch:word) {
            if(node->children[ch-'a'] == nullptr) {
                return false;
            }
            node = node->children[ch-'a'];
        }

        return node->end == true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(auto ch:prefix) {
            if(node->children[ch-'a'] == nullptr) {
                return false;
            }
            node = node->children[ch-'a'];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */ 

int main() {
    Trie* obj = new Trie();
    obj->insert("apple");
    cout << obj->search("apple") << endl;
    cout << obj->search("app") << endl;
    cout << obj->startsWith("a") << endl;
    cout << obj->startsWith("apple") << endl;

    obj->insert("app");
    cout << obj->search("app") << endl;

    return 0;
}
