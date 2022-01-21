#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size()<2) {
            return false;
        }

        vector<int> array = nums;
        sort(array.begin(), array.end());
        
        vector<int> leftSum(nums.size(), 0);
        vector<int> rightSum(nums.size(), 0);

        int sum = 0;
        for(int i =0;i<nums.size();i++) {
            sum += nums[i];
            leftSum[i] = sum;
        }

        sum = 0;
        for(int i =nums.size()-1;i>=0;i--) {
            sum += nums[i];
            rightSum[i] = sum;
        }

        int i =1;
        int j =1;

        while(true) {

            int tmpA = leftSum[j] - leftSum[i];
            int tmpB = leftSum[i] + rightSum[j];

            if(tmpA > tmpB) {
                i++;
            } else if (tmpA < tmpB) {
                j++;
            } else {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {1,5,11,5};
    cout << solution.canPartition(nums) << endl;

    return 0;
}
