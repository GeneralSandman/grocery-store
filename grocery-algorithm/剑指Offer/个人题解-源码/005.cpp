#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {

        if(words.size() < 2) {
            return 0;
        }

        vector<unsigned int> masks(words.size(), 0);
        for(int i=0;i<words.size();i++) {
            for(auto ch:words[i]) {
                masks[i] |= (1<<(ch-'a'));
            }
        }

        int result = 0;
        for(int i=0;i<words.size();i++) {
            for(int j=i+1;j<words.size();j++) {
                if((masks[i] & masks[j]) == 0) {
                    result = max(result, int(words[i].size() * words[j].size()));
                }
            }
        }

        return result;

    }
};


int main() {
    Solution solution;

    vector<string> words = {"abcw","baz","foo","bar","fxyz","abcdef"};
    cout << solution.maxProduct(words) << endl;

    return 0;
}
