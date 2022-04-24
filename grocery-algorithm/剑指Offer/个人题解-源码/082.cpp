#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if(candidates.size()==0) {
            return result;
        }

        sort(candidates.begin(), candidates.end());

        vector<int> currentPath;
        dfs(candidates, target, 0, currentPath, result);
        return result;
    }

    void dfs(vector<int>& candidates, int target, int index, vector<int> &currentPath, vector<vector<int>>& result) {
        if(target < 0) {
            return;
        }
        if(target == 0) {
            result.push_back(currentPath);
            return;
        }

        if(candidates.size() <= index) {
            return;
        }

        dfs(candidates, target, getNextIndex(candidates, index), currentPath, result);

        currentPath.push_back(candidates[index]);
        dfs(candidates, target-candidates[index], index+1, currentPath, result);
        currentPath.erase(--currentPath.end());
    }

    int getNextIndex(vector<int>& candidates, int index) {
        int result = index;
        while(result < candidates.size() && candidates[result] == candidates[index]) {
            result ++;
        }
        return result;
    }
};

int main() {
    Solution s;

    vector<int> nums = {10,1,2,7,6,1,5};

    auto result = s.combinationSum2(nums, 8);
    cout << "--" << endl;
    for(auto array: result) {
        for(auto t: array) {
            cout << t << " ";
        }
        cout << endl;
    }

    return 0;
}
