#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        if(nums.size()==1) {
            return nums[0];
        }
        if(nums.size()==2) {
            return max(nums[0], nums[1]);
        }

        vector<int> result(nums.size(), 0);

        result[0] = nums[0];
        result[1] = max(nums[0], nums[1]);

        for(int i=2;i<nums.size();i++) {
            result[i] = max(result[i-1], result[i-2]+nums[i]);
        }

        return result[result.size()-1];
    }
};

class Solution1 {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        if(nums.size()==1) {
            return nums[0];
        }
        if(nums.size()==2) {
            return max(nums[0], nums[1]);
        }

        vector<int> result(2, 0);

        result[0] = nums[0];
        result[1] = max(nums[0], nums[1]);

        int i = 2;

        for(i=2;i<nums.size();i++) {
            result[i%2] = max(result[(i-1)%2], result[(i-2)%2]+nums[i]);
        }

        return result[(i-1)%2];
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1,2,3,1};
    cout << solution.rob(nums1) << endl;

    vector<int> nums2 = {2,7,9,3,1};
    cout << solution.rob(nums2) << endl;

    return 0;
}
