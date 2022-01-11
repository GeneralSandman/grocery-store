#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hashTable;

        hashTable[0] = -1;

        int result  = 0;

        int sum0toI = 0;

        for(int i=0;i<nums.size();i++) {
            if(nums[i] == 0) {
                sum0toI += -1;
            } else {
                sum0toI += 1;
            }
            if(hashTable.find(sum0toI) == hashTable.end()) {
                hashTable[sum0toI] = i;
            } else {
                result = max(result, i - hashTable[sum0toI]);
            }
        }

        return result;
    }
};


int main() {
    Solution solution;

    vector<int> nums = {0,0, 1,1,1,1, 0};
    int k = 2;

    cout << solution.findMaxLength(nums) << endl;

    return 0;
}
