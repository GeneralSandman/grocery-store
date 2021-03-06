#include <iostream>
#include <vector>
#include <string.h>
#include <map>

using namespace std;

class MapSum {
    class TreeNode {
    public:
        int value;
        TreeNode* children[26];
        TreeNode() {
            value = -1;
            memset(children, 0, sizeof(children));
        }
    };
    TreeNode* root;
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TreeNode();
    }
    
    void insert(string key, int val) {

        TreeNode* node = root;
        for(int i=0;i<key.size();i++) {

            char ch = key[i];
            if(node->children[ch-'a'] == nullptr) {
                TreeNode* newNode = new TreeNode();
                node->children[ch-'a'] = newNode;
            } 

            node = node->children[ch-'a'];

            if(i==key.size()-1) {
                node->value = val;
            }
        }
    }
    
    int sum(string prefix) {
        TreeNode* node = root;

        for(int i=0;i<prefix.size();i++) {
            char ch = prefix[i];

            if(node->children[ch-'a'] == nullptr) {
                return 0;
            }

            node = node->children[ch-'a'];
        }

        return sumTree(node);
    }

    int sumTree(TreeNode* node) {
        if(node == nullptr) {
            return 0;
        }

        int sum = 0;

        if(node->value > 0) {
            sum += node->value;
        }

        for(int i=0;i<26;i++) {
            if(node->children[i] != nullptr) {
                sum += sumTree(node->children[i]);
            }
        }

        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

int main() {
    MapSum* obj = new MapSum();
    obj->insert("apple", 3);
    cout <<  obj->sum("ap") << endl;

    obj->insert("app", 2);
    cout <<  obj->sum("ap") << endl;

    return 0;
}
