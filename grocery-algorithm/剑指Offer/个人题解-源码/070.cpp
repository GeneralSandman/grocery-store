#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

// 全部元素执行异或操作
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int result = 0;

        for(auto num:nums) {
            result ^= num;
        }

        return result;
    }
};

class Solution2 {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) {
            return nums[0];
        }
        int begin = 0;
        int end = nums.size() - 1;
        int middle;
        while (begin < end)
        {
            middle = (begin + end) / 2;

            if(end-begin == 1) {
                middle += 1;
                break;
            }

            if(middle %2==0) {
                if(nums[middle] == nums[middle+1]) {
                    begin = middle;
                } else {
                    end = middle-1;
                }
            } else {
                if(nums[middle-1] == nums[middle]) {
                    begin = middle;
                } else {
                    end = middle-1;
                }
            }
        }

        return nums[middle];
    }
};

class Solution3 {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int result = 0;

        for(auto num:nums) {
            result ^= num;
        }

        return result;
    }
};


int main1() {
    Solution solution;

    vector<int> nums1 = {1,1,2,3,3,4,4,8,8};
    cout << solution.singleNonDuplicate(nums1) << endl;

    vector<int> nums2 = {3,3,7,7,10,11,11};
    cout << solution.singleNonDuplicate(nums2) << endl;



    return 0;
}

int main2() {
    Solution2 solution;

    vector<int> nums1 = {1,1,2,3,3,4,4,8,8};
    cout << solution.singleNonDuplicate(nums1) << endl;

    vector<int> nums2 = {3,3,7,7,10,11,11};
    cout << solution.singleNonDuplicate(nums2) << endl;

    vector<int> nums3 = {1,1,2};
    cout << solution.singleNonDuplicate(nums3) << endl;

    vector<int> nums4 = {1};
    cout << solution.singleNonDuplicate(nums4) << endl;

    vector<int> nums5 = {1,1,2,3,3};
    cout << solution.singleNonDuplicate(nums5) << endl;

    return 0;
}

int main() {
    Solution3 solution;

    vector<int> nums1 = {1,1,2,3,3,4,4,8,8};
    cout << solution.singleNonDuplicate(nums1) << endl;

    vector<int> nums2 = {3,3,7,7,10,11,11};
    cout << solution.singleNonDuplicate(nums2) << endl;

    vector<int> nums3 = {1,1,2};
    cout << solution.singleNonDuplicate(nums3) << endl;

    vector<int> nums4 = {1};
    cout << solution.singleNonDuplicate(nums4) << endl;

    vector<int> nums5 = {1,1,2,3,3};
    cout << solution.singleNonDuplicate(nums5) << endl;

    return 0;
}
