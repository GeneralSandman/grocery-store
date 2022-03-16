#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <unordered_map>

using namespace std;

class Solution {
    class TrieNode {
        public:
            TrieNode *children[26];
            TrieNode() {
                memset(children, 0, sizeof(children));
            }
    };

private:
    TrieNode *root;

public:
    int minimumLengthEncoding(vector<string>& words) {
        buildTrieTree(words);
        int path = 0;
        int result = 0;
        dfs(root, path, result);
        return result;
    }

    int buildTrieTree(vector<string>& words) {
        root = new TrieNode();

        for (auto word : words)
        {
            TrieNode *parent = root;
            for (int i = word.size() - 1; i >= 0;i--) {
                char ch = word[i];
                if (parent->children[ch - 'a'] == nullptr)
                {
                    parent->children[ch - 'a'] = new TrieNode();
                }
                parent = parent->children[ch - 'a'];
            }
                    
        }
    }

    void dfs(TrieNode* node, int path, int& result) {
        bool isLeaf = true;
        for (int i = 0; i < 26; i++)
        {
            if(node->children[i] == nullptr) {
                continue;
            }
            isLeaf = false;
            dfs(node->children[i], path + 1, result);
        }
        if(isLeaf)
            result += path + 1;
    }
};

int main() {
    Solution solution;

    vector<string> words = { "time", "me", "bell"};
    // vector<string> words = { "te", "te", "b"};
    cout << solution.minimumLengthEncoding(words) << endl;

    return 0;
}
