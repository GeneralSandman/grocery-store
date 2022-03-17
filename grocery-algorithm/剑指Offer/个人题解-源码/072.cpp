#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x;

        while(left <= right) {
            int middle = left + (right - left) / 2;
            if(middle <= x / middle) {
                if((middle+1) > x / (middle+1)) {
                    return middle;
                }
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        return 0;
    }
};

int main() {
    Solution solution;

    return 0;
}
