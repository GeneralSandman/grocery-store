#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int divide(int a, int b) {
        return a >> 1;
    }
};

int main() {
    Solution solution;

    cout << solution.divide(15, 2) << endl;

    return 0;
}
