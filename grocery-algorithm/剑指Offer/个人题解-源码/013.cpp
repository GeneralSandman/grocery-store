#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class NumMatrix {
private:
    vector<vector<int> > lineSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++) {
            vector<int> tmp(matrix[0].size()+1);
            int sum = 0;
            // tmp.push_back(0);
            for(int j=0;j<matrix[0].size();j++) {
                sum += matrix[i][j];
                tmp[j+1] = sum;
            }
            lineSum.push_back(tmp);
        }

        // for(auto t:lineSum) {
        //     for(auto i:t) {
        //         cout << i << " ";
        //     }
        //     cout << endl;
        // }

        // cout << endl;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int result = 0;
        for(int i=row1; i<=row2; i++) {
            result += lineSum[i][col2+1] - lineSum[i][col1];
        }

        return result;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main() {

    vector<vector<int>> matrix = {
        {3,0,1,4,2},
        {5,6,3,2,1},
        {1,2,0,1,5},
        {4,1,0,1,7},
        {1,0,3,0,5},
    };

    NumMatrix* obj = new NumMatrix(matrix);
    cout << obj->sumRegion(2,1,4,3) << endl;
    cout << obj->sumRegion(1,1,2,2) << endl;
    cout << obj->sumRegion(1,2,2,4) << endl;


    return 0;
}
