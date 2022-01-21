#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<int> red(costs.size(), 0);
        vector<int> green(costs.size(), 0);
        vector<int> blue(costs.size(), 0);

        red[0] = costs[0][0];
        green[0] = costs[0][1];
        blue[0] = costs[0][2];

        for(int i=1; i<red.size(); i++) {
            red[i] = min(green[i-1], blue[i-1]) + costs[i][0];

            green[i] = min(red[i-1], blue[i-1]) + costs[i][1];

            blue[i] = min(red[i-1], green[i-1]) + costs[i][2];
        }


        return min(red[red.size()-1], min(green[green.size()-1], blue[blue.size()-1]));
    }
};

int main() {
    Solution solution;

    vector<vector<int>> costs1 = {
        {17,2,17},
        {16,16,5},
        {14,3,19},
    };
    cout << solution.minCost(costs1) << endl;

    vector<vector<int>> costs2 = {
        {7,6,2},
    };
    cout << solution.minCost(costs2) << endl;

    return 0;
}
