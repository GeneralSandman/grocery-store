#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

// 超出时间限制
// 从中间开始 往两边扩展
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;


        for (int i = 0; i < heights.size();i++) {
            int height = heights[i];
            int width  = 0;

            int a = findLeftFirstLess(heights, i);
            int b = findRightFirstLess(heights, i);
            width = b - a + 1;


            result = max(result, height * width);
        }


        return result;
    }

    int findLeftFirstLess(vector<int>& heights, int end) {
        for (int i = end; i >= 0;i--) {
            if(heights[end] > heights[i]) {
                return i + 1;
            }
        }

        return 0;
    }

    int findRightFirstLess(vector<int>& heights, int begin) {
        for (int i = begin; i < heights.size();i++) {
            if(heights[begin] > heights[i]) {
                return i - 1;
            }
        }
        return heights.size() - 1;
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {2,1,5,6,2,3};
    cout << solution.largestRectangleArea(nums1) << endl;

    vector<int> nums2 = {2,4};
    cout << solution.largestRectangleArea(nums2) << endl;

    return 0;
}
