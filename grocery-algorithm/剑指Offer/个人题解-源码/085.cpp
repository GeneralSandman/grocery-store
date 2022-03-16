#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if(n <= 0) {
            return result;
        }

        helper(n, n, "", result);
        return result;
    }

    void helper(int left, int right, string path, vector<string> &result) {

        if(left == 0 && right == 0) {
            result.push_back(path);
            return;
        }

        if(left >= 1) {
            helper(left - 1, right, path + "(", result);
        }

        if(right >=1 && right>left) {
            helper(left, right - 1, path + ")", result);
        }
    }
};

int main() {
    Solution solution;

    auto result = solution.generateParenthesis(3);
    for(auto t:result) {
        cout << t << endl;
    }

    return 0;
}
