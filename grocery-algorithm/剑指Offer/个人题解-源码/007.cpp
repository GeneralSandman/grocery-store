#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > result;

        if(nums.size() < 3) {
            return result;
        }

        sort(nums.begin(), nums.end());

        // for(auto t:nums) {
        //     cout << t << " ";
        // }
        // cout << endl;

        for(int i=0;i<nums.size()-2;) {
            findTwoSum(nums, i, result);

            int tmp =nums[i];
            i++;
            while(i<nums.size() && nums[i] == tmp) {
                i++;
            }
        }


        return result;
    }

    // 逆向
    // 头尾 双指针
    void findTwoSum(vector<int>& nums, int i, vector<vector<int> > &result) {
        int j = i+1;
        int k = nums.size()-1;
        while(j<k) {
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < 0) {
                j++;
            } else if(sum > 0) {
                k--;
            } else {
                result.push_back(vector<int> {nums[i],nums[j],nums[k]});

                int tmp = nums[j];
                j++;
                while(j<k && tmp == nums[j]) {
                    j++;
                }
            }

        }
    }

};

int main() {
    Solution solution;

    vector<int> nums = {-1,0,1,2,-1,-4};
    solution.threeSum(nums);

    return 0;
}
