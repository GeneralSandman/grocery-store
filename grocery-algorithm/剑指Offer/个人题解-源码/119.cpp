#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

// https://leetcode-cn.com/problems/WhsWhI/solution/ha-xi-biao-by-wang-xiang-zheng-nan-hai-0bdc/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> accessTable;
        for(auto num:nums) {
            accessTable[num] = false;
        }

        int result = 0;

        for (int i = 0; i < nums.size();i++) {
            int left = nums[i] - 1;
            int right = nums[i] + 1;

            while (accessTable.end() != accessTable.find(left) && accessTable[left] == false) {
                accessTable[left] = true;
                left -= 1;
            }


            while (accessTable.end() != accessTable.find(right) && accessTable[right] == false) {
                accessTable[right] = true;
                right += 1;
            }

            result = max(result, right-left-1);
        }


        return result;
    }
};

int main() {
    Solution solution;

    return 0;
}
