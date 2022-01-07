#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {

private:
    static bool compare(pair<int,int> &a, pair<int,int> &b) {
        return a.second < b.second;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        map<int, int> hashTable;
        for(auto num:nums) {
            hashTable[num] += 1;
        }

        priority_queue<pair<int,int>, vector<pair<int,int> >, decltype(&compare)> maxHeap(compare); 
        for(auto iter=hashTable.begin(); iter!=hashTable.end(); iter++) {
            int value = iter->first;
            int num = iter->second;
            // cout << value << "-" << num << endl;
            // auto p = make_pair(value, num);
            // maxHeap.emplace(num, value);
            maxHeap.emplace(value, num);
        }

        vector<int> result;

        for(int i=0;i<k;i++) {
            if(maxHeap.empty()) {
                break;
            }
            auto top = maxHeap.top();
            result.push_back(top.first);
            maxHeap.pop();
        }


        return result;
    }
};

int main() {
    Solution s;

    vector<int> nums1 = {1,1,1,2,2,3};
    int k = 2;
    auto result = s.topKFrequent(nums1, k);
    for(auto t:result) {
        cout << t << endl;
    }
    cout << endl;

    return 0;
}
