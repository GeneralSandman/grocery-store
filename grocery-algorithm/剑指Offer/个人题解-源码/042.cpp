#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class RecentCounter {
private:
    queue<int> data;
public:
    RecentCounter() {
    }
    
    int ping(int t) {

        data.push(t);

        int begin = t - 3000;

        while(!data.empty()) {
            if(data.front() < begin) {
                data.pop();
            } else {
                break;
            }
        }

        return data.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main() {
    RecentCounter s;
    cout << s.ping(1) << endl;
    cout << s.ping(100) << endl;
    cout << s.ping(3001) << endl;
    cout << s.ping(3002) << endl;

    return 0;
}
