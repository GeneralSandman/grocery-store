#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size();
        int between;

        do {
            between = begin + (end - begin) / 2;
            if(target < nums[between]) {
                end = between;
            } else if (target > nums[between]) {
                begin = between;
            } else {
                break;
            }
            between = begin + (end - begin) / 2;
        } while(begin < end);

        if(nums[between] == target) {
            return between;
        }
        return between + 1;

    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1,3,5,6};
    cout << solution.searchInsert(nums1, 5) << endl;

    vector<int> nums2 = {1,3,5,6};
    cout << solution.searchInsert(nums2, 2) << endl;

    return 0;
}
