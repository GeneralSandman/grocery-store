#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size() <=0 || s1.size() > s2.size()) {
            return false;
        }

        vector<int> hashTable(26,0);
        for(auto ch:s1) {
            hashTable[ch-'a'] += 1;
        }

        vector<int> tmp(26,0);

        for(int i = 0;i<s1.size();i++) {
            tmp[s2[i]-'a'] += 1;
        }

        int i = 0;
        int j = s1.size();
        while(j<s2.size()) {
            if(tmp == hashTable) {
                return true;
            }

            tmp[s2[i]-'a'] --;
            tmp[s2[j]-'a'] ++;

            i++;
            j++;

        }

        if(tmp == hashTable) {
                return true;
            }

        return false;
    }

    // bool checkSameArray(string)
};

int main() {
    Solution solution;

    cout << solution.checkInclusion("ab", "aboooooo") << endl;
    cout << solution.checkInclusion("ab", "eidbaooo") << endl;
    cout << solution.checkInclusion("ab", "eidboaoo") << endl;
    cout << solution.checkInclusion("ab", "xxxxxab") << endl;
    cout << solution.checkInclusion("adc", "dcda") << endl;

    return 0;
}
