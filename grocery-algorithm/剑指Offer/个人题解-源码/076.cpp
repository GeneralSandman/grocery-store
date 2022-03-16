#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>

using namespace std;

class Solution {
private:
    static bool compare(int a, int b) {
        return a < b;
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, decltype(&compare)> maxHeap(compare);

        for(auto num:nums) {
            maxHeap.emplace(num);
        }

        for (int i = 0; i < k-1;i++) {
            maxHeap.pop();
        }

        return maxHeap.top();
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {3,2,1,5,6,4};
    cout << solution.findKthLargest(nums1, 2) << endl;

    vector<int> nums2 = {3,2,3,1,2,4,5,5,6};
    cout << solution.findKthLargest(nums2, 4) << endl;

    return 0;
}
