#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
private:
    bool isPalindrome(string &s, int begin, int end) {
        while(begin < end) {
            if(s[begin++] != s[end--]) {
                return false;
            }
        }
        return true;
    }

    void helper(string &s, int begin, vector<string>&path, vector<vector<string> > &result) {

        if(begin == s.size()) {
            result.push_back(path);
        }

        for (int i = begin; i < s.size();i++) {
            if(isPalindrome(s, begin, i)) {
                string tmp = s.substr(begin, i-begin+1);
                // cout << tmp << endl;
                path.push_back(tmp);
                helper(s, i+1, path, result);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<string> > partition(string s) {
        vector<vector<string> > result;
        vector<string> tmp;
        helper(s, 0, tmp, result);

        return result;
    }
};

int main() {
    Solution solution;

    auto result = solution.partition("google");
    for(auto res:result) {
        for(auto t:res) {
            cout << t << " ";
        }
        cout << endl;
    }

    return 0;
}
