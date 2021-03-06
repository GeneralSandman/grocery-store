#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> hashTable;

        for(auto t:arr1) {
            hashTable[t] += 1;
        }

        vector<int> result;

        for(auto t:arr2) {
            auto iter = hashTable.find(t);
            for(int i=0;i<hashTable[t];i++) {
                result.push_back(t);
            }
            hashTable.erase(iter);
        }

        for(auto iter = hashTable.begin(); iter != hashTable.end(); iter++) {
            for(int i=0;i<iter->second;i++) {
                result.push_back(iter->first);
            }
            // cout << iter->first << endl;
        }


        return result;
    }
};

int main() {
    Solution s;


    vector<int> array1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> array2 = {2,1,4,3,9,6};
    auto result = s.relativeSortArray(array1, array2);
    for(auto t: result) {
        cout << t << endl;
    }
    cout << endl;

    return 0;
}
