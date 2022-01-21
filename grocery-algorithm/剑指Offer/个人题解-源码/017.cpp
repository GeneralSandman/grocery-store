#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        if(s.size() <=0 || s.size() < t.size()) {
            return "";
        }

        vector<int> hashTable(26,0);
        for(auto ch:t) {
            hashTable[ch-'a'] ++;
        }


        vector<int> tmp(26,0);
        for(int i = 0;i<t.size();i++) {
            insertHelper(hashTable, tmp, s[i]);
        }

        string result = "";

        int i = 0;
        int j = t.size();

        while(j<s.size()) {
            if(tmp == hashTable) {
                if(result == "") {
                    result = s.substr(i, j-i);
                }
                if(j-i<result.size()) {
                    result = s.substr(i, j-i);
                }
            }

            deleteHelper(hashTable, tmp, s[i]);
            insertHelper(hashTable, tmp, s[j]);

            i++;
            j++;
        }

        if(tmp == hashTable) {
            if(result == "") {
                result = s.substr(i, j-i);
            }
            if(j-i<result.size()) {
                result = s.substr(i, j-i);
            }
        }

        return result;
    }

    void insertHelper(vector<int> &hashTable, vector<int> &tmp, char ch) {
        if(hashTable[ch-'a'] == 0) {
            return;
        }

        tmp[ch-'a'] ++;
    }

    void deleteHelper(vector<int> &hashTable, vector<int> &tmp, char ch) {
        if(hashTable[ch-'a'] == 0) {
            return;
        }

        tmp[ch-'a'] --;
    }

};


int main() {
    Solution s;

    cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;

    return 0;
}
