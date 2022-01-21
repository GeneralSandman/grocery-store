#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<int> last0Result(s.size(), 0);
        vector<int> last1Result(s.size(), 0);

        if(s[0] == '1') {
            last0Result[0] = 1;
        } else if (s[0] == '0') {
            last1Result[0] = 1;
        }

        for(int i=1;i<s.size();i++) {
            if(s[i] == '1') {
                last0Result[i] =last0Result[i-1] + 1;
                last1Result[i] = min(last0Result[i-1], last1Result[i-1]);
            } else if(s[i] == '0') {
                last0Result[i] = last0Result[i-1];
                last1Result[i] = min(last0Result[i-1], last1Result[i-1]) + 1;
            }
        }

        return min(last0Result[s.size()-1], last1Result[s.size()-1]);
    }
};

int main() {
    Solution solution;

    cout << solution.minFlipsMonoIncr("00110") << endl;
    cout << solution.minFlipsMonoIncr("010110") << endl;
    cout << solution.minFlipsMonoIncr("00011000") << endl;

    return 0;
}
