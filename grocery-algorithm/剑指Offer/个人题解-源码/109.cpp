#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        set<string> deadendsSet;
        for(auto t:deadends) {
            deadendsSet.insert(t);
        }

        if(deadendsSet.find(target) != deadendsSet.end() 
            || deadendsSet.find("0000") != deadendsSet.end()) {
            return -1;
        }


        queue<string> q1;
        queue<string> q2;
        int length = 0;
        set<string>   visited;

        q1.push("0000");
        visited.insert("0000");
        while (q1.size()) {
            string front = q1.front();
            q1.pop();

            if(front == target) {
                return length;
            }

            auto nexts = getNexts(front);
            for(auto next:nexts) {
                if(deadendsSet.find(next) != deadendsSet.end() || visited.find(next) != visited.end()) {
                    continue;
                }
                q2.push(next);
                visited.insert(next);
                
            }


            if(q1.empty()) {
                length++;
                swap(q1, q2);
            }
        }

        return -1;
    }

    vector<string> getNexts(string start) {
        vector<string> result;

        for (int i = 0;i<start.size();i++) {
            string tmp;

            tmp = start;
            tmp[i] = (tmp[i] == '0') ? '9' : (tmp[i] - 1);
            result.push_back(tmp);

            tmp    = start;
            tmp[i] = (tmp[i] == '9') ? '0' : (tmp[i] + 1);
            result.push_back(tmp);
        }

        return result;
    }
};

int main() {
    Solution solution;

    vector<string> deadends1 = {"0201","0101","0102","1212","2002"};
    string         target1 = "0202";
    cout << solution.openLock(deadends1, target1) << endl;


    vector<string> deadends2 = {"8888"};
    string         target2 = "0009";
    cout << solution.openLock(deadends2, target2) << endl;


    vector<string> deadends3 = {"8887","8889","8878","8898","8788","8988","7888","9888"};
    string         target3 = "8888";
    cout << solution.openLock(deadends3, target3) << endl;

    return 0;
}
