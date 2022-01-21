#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        vector<int> result(cost.size()+1, 0);
        for(int i=2;i<=cost.size();i++) {
            result[i] = min(result[i-1] + cost[i-1], result[i-2] + cost[i-2]);
        }

        return result[cost.size()];
    }
};

class Solution2 {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        vector<int> result(2, 0);

        int i = 2;
        for (i = 2; i <= cost.size(); i++)
        {
            result[i%2] = min(result[(i-1)%2] + cost[i-1], result[(i-2)%2] + cost[i-2]);
        }

        return result[(i+1)%2];
    }
};

int main() {
    Solution solution;

    vector<int> cost1 = {10, 15, 20};
    cout << solution.minCostClimbingStairs(cost1) << endl;

    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << solution.minCostClimbingStairs(cost2) << endl;



    return 0;
}
