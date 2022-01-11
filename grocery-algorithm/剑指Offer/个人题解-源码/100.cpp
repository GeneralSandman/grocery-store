#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        if(triangle.empty()) {
            return -1;
        }

        vector<int> result;

        for(int j=0;j<triangle[triangle.size()-1].size();j++){
            result.push_back(triangle[triangle.size()-1][j]);
        }


        for(int i=triangle.size()-2; i>=0; i--) {
            for(int j=0;j<triangle[i].size(); j++) {
                result[j] = triangle[i][j] + min(result[j], result[j+1]);
            }
        }

        return result[0];
    }
};

int main() {
    Solution solution;

    vector<vector<int>> matrix = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3},
    };

    cout  << solution.minimumTotal(matrix) << endl;

    return 0;
}
