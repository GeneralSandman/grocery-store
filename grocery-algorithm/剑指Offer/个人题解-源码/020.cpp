#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;

        for (int i = 0; i < s.size();i++) {
            result += helper(s, i, i);
            result += helper(s, i, i + 1);
        }
        return result;
    }

    int helper(string &s, int begin, int end) {
        int result = 0;
        while (0 <= begin && end < s.size() && s[begin] == s[end]) {
            begin--;
            end++;
            result++;
        }

        return result;
    }
};

int main() {
    Solution solution;

    return 0;
}
