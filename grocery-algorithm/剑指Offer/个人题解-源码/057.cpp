#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long int> windows;

        for (int i = 0; i < nums.size();i++) {

            long long int min = (long long int)nums[i] - t;
            long long int max = (long long int)nums[i] + t;

            auto iter = windows.lower_bound(min);

            if(iter != windows.end() && (*iter) <= max) {
                return true;
            }

            windows.insert(nums[i]);
            // if (windows.size() >= k) // 这样写会失败，因为可能有set里没有重复的元素，
            if (i >= k)
            {
                windows.erase(nums[i-k]);
            }
        }

        return false;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {1,2,3,1};
    cout << solution.containsNearbyAlmostDuplicate(nums, 3, 0) << endl;

    return 0;
}
