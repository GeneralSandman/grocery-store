#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;


class Solution {
private:
    int sum;
    vector<int> sumIndex;
public:
    Solution(vector<int>& w) {
        this->sum = 0;
        for(auto c:w) {
            this->sum += c;
            sumIndex.push_back(this->sum);
        }


        // for(auto t:sumIndex) {
            // cout << t << " ";
        // }
        // cout << endl;
    }
    
    int pickIndex() {
        srand((unsigned)time(NULL));
        int index = rand()%this->sum;

        for(int i=0;i<sumIndex.size();i++) {
            if(index > sumIndex[i]) {
                return i;
            }
        }

        return 0;

    }
};

int main() {
    vector<int> nums1 = {1, 2, 3, 4};
    Solution solution(nums1);

    return 0;
}
