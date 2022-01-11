#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> matrix = grid;

        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(i==0 && j==0) {
                    continue;
                }
                int tmp = INT_MAX;
                if(i-1>=0) {
                    tmp = min(tmp, matrix[i-1][j]);
                }
                if(j-1>=0) {
                    tmp = min(tmp, matrix[i][j-1]);
                }
                matrix[i][j] = grid[i][j] + tmp;
            }
        }

        return matrix[matrix.size()-1][matrix[0].size()-1];
    }
};

int main() {
    Solution solution;

    vector<vector<int>> matrix = {
        {1,3,1},
        {1,5,1},
        {4,2,1},
    };

    cout  << solution.minPathSum(matrix) << endl;

    return 0;
}
