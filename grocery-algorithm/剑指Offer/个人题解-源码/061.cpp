#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>

using namespace std;

class Solution {
    static bool compare(pair<int,int> &a, pair<int,int> &b) {
        return a.first + a.second > b.first + b.second;
    }

public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(&compare)> minHeap(compare);

        for (int i = 0; i < nums1.size();i++) {
            for (int j = 0; j < nums2.size();j++) {
                // cout << nums1[i] << "-" << nums2[j] << endl;
                minHeap.emplace(nums1[i], nums2[j]);
            }
        }

        vector<vector<int>> result;

        for (int i = 0; i < k;i++) {
            if(minHeap.empty()){
                break;
            }
            auto top = minHeap.top();
            minHeap.pop();
            vector<int> tmp = {top.first, top.second};
            result.push_back(tmp);
        }

        return result;
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1,7,11};
    vector<int> nums2 = {2,4,6};


    auto result = solution.kSmallestPairs(nums1, nums2, 3);

    for(auto t:result) {
        for(auto tmp:t) {
            cout << tmp << " ";
        }
        cout << endl;
    }

    return 0;
}
