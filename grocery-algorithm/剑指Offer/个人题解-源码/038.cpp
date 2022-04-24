#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> accessPath;
        vector<int> result(temperatures.size(), 0);


        for (int i = 0; i < temperatures.size();i++) {
            if(accessPath.empty()) {
                accessPath.push(i);
                continue;
            } 

            if(temperatures[accessPath.top()] >= temperatures[i]) {
                accessPath.push(i);
                continue;
            }

            
            while(!accessPath.empty()
                && temperatures[accessPath.top()] < temperatures[i]) {
                int pre_index = accessPath.top();
                accessPath.pop();

                result[pre_index] = i - pre_index;
            }

            accessPath.push(i);
        }


        return result;
    }
};

int main() {
    Solution s;

    vector<int> nums1 = {73, 74, 75, 71, 69, 72, 76, 73};
    auto result1 = s.dailyTemperatures(nums1);
    for(auto t:result1) {
        cout << t << " ";
    }
    cout << endl;


    vector<int> nums2 = {35, 31, 33, 36, 34};
    auto result2 = s.dailyTemperatures(nums2);
    for(auto t:result2) {
        cout << t << " ";
    }
    cout << endl;

    return 0;
}
