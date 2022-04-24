#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;


// https://leetcode-cn.com/problems/gaM7Ch/solution/zui-shao-de-ying-bi-shu-mu-by-leetcode-s-rm0w/#comment
class Solution {
public:
    int coinChange(vector<int>& nums, int target) {
        vector<int> dp(target + 1, target + 1);
        dp[0] = 0;

        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size();j++) {
                if(i >= nums[j]) {
                    dp[i] = min(dp[i], dp[i - nums[j]] + 1);
                }
            }
        }

        if(dp[target] > target) {
            return -1;
        } else {
            return dp[target];
        }
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {2, 3, 5};
    cout << solution.combinationSum4(nums1, 2) << endl;
    cout << solution.combinationSum4(nums1, 3) << endl;
    cout << solution.combinationSum4(nums1, 5) << endl;
    cout << solution.combinationSum4(nums1, 10) << endl;

    return 0;
}
