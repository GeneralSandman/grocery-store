#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> tmp;

        for(auto asteroid:asteroids) {
            A:
            if(!tmp.empty()) {
                int top = tmp.top();
                if(top > 0 && asteroid < 0) {
                    if(abs(top) < abs(asteroid)) {
                        // 之前的炸没了
                        tmp.pop();
                        // tmp.push(asteroid);
                        // 继续炸
                        goto A;
                    } else if (abs(top) > abs(asteroid)) {
                        // 这个炸没了
                    } else {
                        tmp.pop();

                    }
                } else {
                    tmp.push(asteroid);
                }
            } else {
                tmp.push(asteroid);
            }
        }


        vector<int> result;
        while(!tmp.empty()) {
            result.insert(result.begin(), tmp.top());
            tmp.pop();
        }
        return result;
    }
};

int main() {
    Solution s;

    vector<int> tmp1 = {5,10,-5};
    vector<int> result1 = s.asteroidCollision(tmp1);
    for(auto t:result1) {
        cout << t << endl;
    }
    cout << endl;

    vector<int> tmp2 = {8,-8};
    vector<int> result2 = s.asteroidCollision(tmp2);
    for(auto t:result2) {
        cout << t << endl;
    }
    cout << endl;

    vector<int> tmp3 = {10,2,-5};
    vector<int> result3 = s.asteroidCollision(tmp3);
    for(auto t:result3) {
        cout << t << endl;
    }
    cout << endl;

    vector<int> tmp4 = {-2,-1,1,2};
    vector<int> result4 = s.asteroidCollision(tmp4);
    for(auto t:result4) {
        cout << t << endl;
    }
    cout << endl;

    return 0;
}
