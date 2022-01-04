#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class MovingAverage {

private:
    int size;
    int num;
    int sum;
    queue<int> slidingWindow;

public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
        sum = 0;
        num = 0;
    }
    
    double next(int val) {
        slidingWindow.push(val);
        sum += val;
        num += 1;

        if(slidingWindow.size() > size) {
            sum -= slidingWindow.front();
            slidingWindow.pop();
            num -= 1;
        }

        
        return double(sum)/num;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

int main() {
    Solution s;

    return 0;
}
