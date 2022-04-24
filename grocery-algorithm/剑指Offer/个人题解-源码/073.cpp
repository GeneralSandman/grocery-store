#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = 0;
        for(auto t:piles) {
            maxPile = max(maxPile, t);
        }


        int left = 1;
        int right = maxPile;


        while(left <= right) {
            int mid = (left+right) / 2;
            int hours = calHours(piles, mid);

            if (hours <= h) {
              if(mid == 1) {
                  return mid;
              }
                
              if(calHours(piles, mid-1) > h) {
                return mid;

              }

                right = mid - 1;
            } else {
                left = mid + 1;
            }

        }


        return -1;

    }

private:
    int calHours(vector<int>& piles, int speed) {
        int result = 0;

        for(auto t:piles) {
            result += t / speed;
            if(t%speed) {
                result +=1;
            }
        }

        return result;
    }
};

int main() {
    Solution solution;


    vector<int> nums1 = {3,6,7,11};
    cout << solution.minEatingSpeed(nums1, 8) << endl;


    vector<int> nums2 = {30,11,23,4,20};
    cout << solution.minEatingSpeed(nums2, 5) << endl;

    vector<int> nums3 = {30,11,23,4,20};
    cout << solution.minEatingSpeed(nums3, 6) << endl;

    return 0;
}
