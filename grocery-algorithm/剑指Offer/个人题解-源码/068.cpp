#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;


        while(left <= right) {

            int mid = (left + right) / 2;
            if(nums[mid] >= target) {
              if(mid == 0) {
                  return 0;
              }

              if (nums[mid-1] < target) {
                  return mid;
              }

              right = mid-1;
            } else {
                left = mid+1;
            }
        }

        return nums.size();
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1,3,5,6};
    cout << solution.searchInsert(nums1, 5) << endl;

    vector<int> nums2 = {1,3,5,6};
    cout << solution.searchInsert(nums2, 2) << endl;

    vector<int> nums3 = {1,3,5,6};
    cout << solution.searchInsert(nums2, 7) << endl;

    vector<int> nums4 = {1,3,5,6};
    cout << solution.searchInsert(nums4, 0) << endl;


    return 0;
}
