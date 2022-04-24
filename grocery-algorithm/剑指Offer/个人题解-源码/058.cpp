#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;


class MyCalendar {
    typedef pair<int, int> sche;
    vector<sche> data;

public:
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        int left = 0;
        int right = data.size();


        while (left < right) {
            int mid = (left+right)/2;
            if(data[mid].second <= start) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        if(left < data.size() && data[left].first < end) {
            return false;
        }


        auto res = sche{start, end};
        data.insert(data.begin() + left, res);

        return true;

    }
};

int main() {

     MyCalendar *myCalendar = new MyCalendar();
     cout << myCalendar->book(10, 20) << endl; // returns true 
     cout << myCalendar->book(15, 25) << endl; // returns false ，第二个日程安排不能添加到日历中，因为时间 15 已经被第一个日程安排预定了
     cout << myCalendar->book(20, 30) << endl; // returns true ，第三个日程安排可以添加到日历中，因为第一个日程安排并不包含时间 20 


    return 0;
}
