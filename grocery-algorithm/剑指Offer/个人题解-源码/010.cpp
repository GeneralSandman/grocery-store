#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int sum0toI = 0;
        unordered_map<int, int> hashTable;

        // 这个初始化很重要
        hashTable[0] = 1;

        int result = 0;
        for(int i=0;i<nums.size();i++) {
            sum0toI += nums[i];

            result += hashTable[sum0toI - k];

            hashTable[sum0toI] += 1;
        }

        return result;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {1,1,1};
    int k = 2;

    cout << solution.subarraySum(nums, k) << endl;

    return 0;
}
