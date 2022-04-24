#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto t:nums) {
            sum += t;
        }

        if(sum%2) {
            return false;
        }

        int target = sum / 2;

        vector<vector<bool> > dp(nums.size() + 1, vector<bool>(target + 1,false ));

        dp[0][0] = true;

        for (int i = 1;i<dp.size();i++) {
            for (int j = 0; j < target + 1; j++) {
                dp[i][j] = dp[i - 1][j];
                if(!dp[i][j] && j - nums[i - 1]>=0) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]];
                }
            }
        }


        return dp[dp.size()-1][target];
    }
};

int main() {
    Solution solution;

    vector<int> nums = {1,5,11,5};
    cout << solution.canPartition(nums) << endl;

    return 0;
}
