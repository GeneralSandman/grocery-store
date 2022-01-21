#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;

// 使用减法代替除法
class Solution {
public:
    int divide(int a, int b) {
        if (b == 0)
            return 0;
        if (a == INT_MIN){
            if (b == -1) return INT_MAX;
            if (b == 1) return INT_MIN;
        }
        if (b == INT_MIN){
            if (a == INT_MIN) return 1;
            else return 0;
        }

        int sign = -1;//判断结果正负
        //a,b均设为负数，防止越界
        if (a > 0) {
            sign = -sign;
            a = -a;
        }
        if (b > 0) {
            sign = -sign;
            b = -b;
        }
        int res = 0;
        while (a <= b){
            a -= b;
            ++res;
        }
        if (sign > 0)
            res = -res;
        return res;
    }
};

int main() {
    Solution solution;

    cout << solution.divide(15, 2) << endl;

    cout << solution.divide(7, -3) << endl;

    cout << solution.divide(0, 1) << endl;

    cout << solution.divide(-1, -1) << endl;

    cout << solution.divide(-2147483648, -1) << endl;

    return 0;
}
