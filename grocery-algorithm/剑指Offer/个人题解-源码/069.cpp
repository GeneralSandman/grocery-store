#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        if(arr.size() < 3) {
            return -1;
        }

        for(int i=1;i<arr.size()-1;i++) {
            if(arr[i-1] < arr[i] && arr[i] > arr[i+1]) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {0,1,0};
    cout << solution.peakIndexInMountainArray(nums1) << endl;

    vector<int> nums2 = {1,3,5,6};
    cout << solution.peakIndexInMountainArray(nums2) << endl;

    return 0;
}
