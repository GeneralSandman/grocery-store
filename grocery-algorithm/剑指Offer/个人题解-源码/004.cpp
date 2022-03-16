#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bitSums(32, 0);

        for (int i = 0; i < 32;i++) {
            for(auto num:nums) {
                bitSums[i] += (num >> i) & 1;
            }
        }

        int result = 0;
        for (int i = 31; i >= 0;i--) {
            result <<= 1;
            result += bitSums[i] % 3;
        }

        return result;
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {2, 2, 2, 4};
    cout << solution.singleNumber(nums1) << endl;


    vector<int> nums2 = {2, 2, 2, 3};
    cout << solution.singleNumber(nums2) << endl;

    return 0;
}
