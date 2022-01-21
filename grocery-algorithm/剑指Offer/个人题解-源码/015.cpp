#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;

        if(s.size() <=0 || s.size() < p.size()) {
            return result;
        }

        vector<int> hashTable(26,0);
        for(auto t:p) {
            hashTable[t-'a'] ++;
        }

        vector<int> tmp(26,0);
        for(int i = 0;i<p.size();i++) {
            tmp[s[i]-'a'] += 1;
        }

        int i = 0;
        int j = p.size();

        while(j<s.size()) {
            if(tmp == hashTable) {
                result.push_back(i);
            }

            tmp[s[i]-'a'] --;
            tmp[s[j]-'a'] ++;

            i++;
            j++;
        }

        if(tmp == hashTable) {
            result.push_back(i);
        }



        return result;
    }
};

int main() {
    Solution s;

    auto result1 = s.findAnagrams("cbaebabacd", "abc");
    for(auto t:result1) {
        cout << t << " ";
    }
    cout << endl;

    auto result2 = s.findAnagrams("abab", "ab");
    for(auto t:result2) {
        cout << t << " ";
    }
    cout << endl;

    return 0;
}
