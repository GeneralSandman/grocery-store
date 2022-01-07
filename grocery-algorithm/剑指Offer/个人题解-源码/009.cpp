#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(nums.empty()) {
            return 0;
        }

        int target = k;

        int begin = 0;
        int end  = 0;

        int result = 0;
        int sum = 1;

        while(end < nums.size()) {
            sum *= nums[end];

            if(sum < target) {
                result += (end-begin+1);
            } else {
                // begin 往前走
                while(begin <= end && sum >= target) {
                    sum = sum/nums[begin];
                    begin += 1;
                }

                result += (end-begin+1);
            }

            end += 1;
        }
        return result;

    }
};

int main() {
    Solution s;

    int target = 100;
    vector<int> nums = {10,5,2,6};
    cout << s.numSubarrayProductLessThanK(nums, target) << endl;

    return 0;
}
