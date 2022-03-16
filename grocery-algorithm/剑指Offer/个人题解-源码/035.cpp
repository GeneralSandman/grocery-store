#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> tP(timePoints.size());

        for (int i = 0; i < timePoints.size();i++) {
            tP[i] = convertTimePointToInt(timePoints[i]);
        }
        sort(tP.begin(), tP.end());

        int result = INT_MAX;
        for (int i = 0; i < tP.size() - 1;i++){
            int tmp = tP[i + 1] - tP[i];
            if(tmp > 12*60) {
                tmp = 24*60 - tmp;
            }
            result  = min(result, tmp);
        }

        int tmp = tP[tP.size() - 1] - tP[0];
        if(tmp > 12*60) {
            tmp = 24*60 - tmp;
        }
        result  = min(result, tmp);

        return result;
    }

    inline int convertTimePointToInt(string timePoint) {
        int result = atoi(timePoint.substr(3,2).c_str());
        result += atoi(timePoint.substr(0, 2).c_str()) * 60;
        return result;
    }
};

int main() {
    Solution solution;

    vector<string> timePoints = {"23:59", "00:00"};
    cout << solution.findMinDifference(timePoints) << endl;

    return 0;
}
