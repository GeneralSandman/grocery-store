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

        vector<int> nums1 = nums;
        vector<int> nums2 = nums;

        nums1.erase(--nums1.end());
        nums2.erase(nums2.begin());

        return max(helper(nums1), helper(nums2));
    }

    int helper(vector<int>& nums) {
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


        return result[nums.size()-1];
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {2,3,2};
    cout << solution.rob(nums1) << endl;

    vector<int> nums2 = {2,3,4,5,3};
    cout << solution.rob(nums2) << endl;

    return 0;
}
