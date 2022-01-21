#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> result(n+1,0);

        for(int i =0;i<result.size();i++) {
            result[i] = result[i/2] + i%2;
        }
        return result;
    }
};

int main() {
    Solution solution;

    auto result1 = solution.countBits(2);
    for(auto t:result1) {
        cout << t << " ";
    }
    cout << endl;

    auto result2 = solution.countBits(5);
    for(auto t:result2) {
        cout << t << " ";
    }
    cout << endl;

    auto result3 = solution.countBits(16);
    for(auto t:result3) {
        cout << t << " ";
    }
    cout << endl;

    return 0;
}
