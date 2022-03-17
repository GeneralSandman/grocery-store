#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> accessPath(m, vector<int>(n, 0));
        accessPath[0][0] = 1;

        for (int i = 0; i < m;i++) {
            for (int j = 0; j < n;j++) {
                int x1 = i - 1;
                int y1 = j;

                int x2 = i;
                int y2 = j - 1;


                if(x1>=0 && y2>=0) {
                    accessPath[i][j] = accessPath[x1][y1] + accessPath[x2][y2];
                } else if (x1>=0 && y2<0) {
                    accessPath[i][j] = accessPath[x1][y1];
                } else if (x1 <0 && y2>=0) {
                    accessPath[i][j] = accessPath[x2][y2];
                }
            }
        }


        return accessPath[m-1][n-1];
    }
};


int main() {
    Solution solution;

    return 0;
}
