#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());

        if(intervals.size()<=1) {
            return intervals;
        }


        vector<vector<int>> result;


        for(auto inter: intervals) {
            int left = inter[0];
            int right = inter[1];


            if(result.empty() || result[result.size()-1][1] < left) {
                result.push_back(vector<int>{left, right});
            } else {
                result[result.size()-1][1] = max(result[result.size()-1][1], right);
            }
        }

        return result;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> intervals1 = {
      {1, 3}, 
      {2, 6}, 
      {8, 10}, 
      {15, 18}, 
    };

    auto res1 = solution.merge(intervals1);
    for(auto tmp:res1) {
      for(auto t:tmp) {
        cout << t << ", ";
      }

      cout << endl;
    }
    cout << "--------------" << endl;

    return 0;
}
