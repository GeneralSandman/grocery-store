#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashTable;

        for(auto str:strs) {
            string old = str;
            sort(str.begin(), str.end());
            hashTable[str].push_back(str);
        }

        vector<vector<string>> result;
        for (auto iter = hashTable.begin(); iter != hashTable.end();iter++) {
            result.push_back(iter->second);
        }

        return result;
    }
};

int main() {
    Solution solution;

    return 0;
}
