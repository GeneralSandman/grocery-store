#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <queue>

using namespace std;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> data;
    int                                            k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto t:nums) {
            add(t);
        }
    }

    int add(int val) {
        data.push(val);
        if(data.size() > this->k) {
            data.pop();
        }

        return data.top();
    }
};


int main() {
    vector<int> init = {4,5,8,2};
    KthLargest s(3, init);
    cout << "---" << s.add(3) << endl;
    cout << "---" << s.add(5) << endl;
    cout << "---" << s.add(10) << endl;
    cout << "---" << s.add(9) << endl;
    cout << "---" << s.add(4) << endl;

    return 0;
}
