#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }
        if(s.size() == 0) {
            return false;
        }
        if(s==t) {
            return false;
        }


        vector<int> hashTableS(26,0);
        vector<int> hashTableT(26,0);
        for(auto ch:s){
            hashTableS[ch-'a'] ++;
        }
        for(auto ch:t){
            hashTableT[ch-'a'] ++;
        }

        for(int i=0;i<26;i++) {
            if(hashTableS[i] != hashTableT[i]) {
                return false;
            }
        }

        return true;


    }
};

int main() {
    Solution solution;

    return 0;
}
