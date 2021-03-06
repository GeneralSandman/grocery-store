#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> hashTable;

        for(int i=0; i<order.size(); i++) {
            hashTable[order[i]] = i;
        }

        bool result = false;
        for(int i=0; i<words.size()-1; i++) {
            string current = words[i];
            string next = words[i+1];
            bool tmp = check(current, next, hashTable);
            if(!tmp) {
                return false;
            }

        }
        return true;
    }

    bool check(string& a, string& b, map<char, int> &hashTable) {
        int i = 0;
        for(int i=0; i<min(a.size(), b.size()); i++) {
            if(hashTable[a[i]] < hashTable[b[i]]) {
                return true;
            } else if ( hashTable[a[i]] > hashTable[b[i]] ) {
                return false;
            }
        }

        // 能走到这里 说明 a b 的前部分肯定是相同的

        if(a.size() > b.size()) {
            return false;
        }

        return true;
    }
};

int main() {
    Solution solution;

    vector<string> words1 = {"apple", "applee"};
    string order = "abcdefghijklmnopqr";
    cout << solution.isAlienSorted(words1, order) << endl;

    

    return 0;
}
