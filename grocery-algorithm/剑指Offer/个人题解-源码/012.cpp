#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        if(nums.empty()) {
            return -1;
        }

        vector<int> leftSum(nums.size(), 0);
        vector<int> rightSum(nums.size(), 0);

        int sum = 0;
        for(int i =0;i<nums.size()-1; i++) {
            sum += nums[i];
            leftSum[i+1] = sum;
        }

        sum = 0;
        for(int i=nums.size()-1;i>0;i--) {
            sum += nums[i];
            rightSum[i-1] = sum;
        }

        for(int i=0;i<nums.size();i++) {
            if(leftSum[i] == rightSum[i]) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {1,7,3,6,5,6};
    cout << solution.pivotIndex(nums) << endl;

    return 0;
}
