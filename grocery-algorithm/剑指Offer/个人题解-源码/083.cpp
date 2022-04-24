#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<int> accessPath;
        unordered_map<int, bool> hasAccess;
        vector<vector<int>> result;

        helper(nums, accessPath, hasAccess, result);
        return result;
    }

    void helper(vector<int>& nums, vector<int>& accessPath, unordered_map<int, bool>& hasAccess, vector<vector<int>> &result) {
      if(accessPath.size() == nums.size()) {
          result.push_back(accessPath);
          return;
      }

      for(int i=0; i<nums.size(); i++) {
          auto iter = hasAccess.find(nums[i]);
          if(iter != hasAccess.end() && hasAccess[nums[i]] == true) {
              continue;
          }

          hasAccess[nums[i]] = true;
          accessPath.push_back(nums[i]);

          helper(nums, accessPath, hasAccess, result);

          hasAccess[nums[i]] = false;
          accessPath.erase(--accessPath.end());
      }

    }
};

int main() {
    Solution solution;

    vector<int> nums = {1, 2, 3};

    auto result = solution.permute(nums);

    for(auto a:result) {
      for(auto t:a) {
        cout << t << " ";
      }
      cout << endl;
    }
    cout << endl;

    return 0;
}
