#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // 双指针
        // 一个在头 一个在尾
        vector<int> result;
        if(numbers.empty()) {
            return result;
        }

        int begin = 0;
        int end = numbers.size()-1;

        while(begin < end) {
            if((numbers[begin] + numbers[end]) > target) {
                end--;
            } else if((numbers[begin] + numbers[end]) < target) {
                begin++;
            } else {
                return vector<int> {begin,end};
            }
        }

        return result;

    }
};

int main() {
    Solution solution;

    return 0;
}
