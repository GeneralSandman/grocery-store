#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        unordered_map<int, set<int>> graph;
        unordered_map<int, int>      inDegrees;

        // build graph
        for (auto seq : seqs) {
            for (auto num : seq) {
                if (num < 1 || num > org.size()) {
                    return false;
                }

                if (graph.find(num) == graph.end()) {
                    graph[num] = set<int>();
                }
                if (inDegrees.find(num) == inDegrees.end()) {
                    inDegrees[num] = 0;
                }
            }

            for (int i = 0; i < seq.size() - 1; i++) {
                int  a    = seq[i];
                int  b    = seq[i + 1];
                auto iter = graph.find(a);
                if (iter->second.find(b) == iter->second.end()) {
                    iter->second.insert(b);
                    inDegrees[b]++;
                }
            }
        }

        // debug
        // for (auto iter = graph.begin(); iter != graph.end(); iter++) {
        // for (auto iterr = iter->second.begin(); iterr != iter->second.end(); iterr++) {
        //     cout << iter->first << " -> " << *iterr << endl;
        //     }
        // }
        // debug


        // check
        queue<int> accessQueue;
        for (auto iter = inDegrees.begin(); iter != inDegrees.end(); iter++) {
            if (iter->second == 0) {
                accessQueue.push(iter->first);
            }
        }

        // access
        vector<int> result;
        while (accessQueue.size() == 1) {
            int front = accessQueue.front();
            accessQueue.pop();
            result.push_back(front);

            auto iter     = graph.find(front);
            auto set_iter = iter->second;
            for (auto t = set_iter.begin(); t != set_iter.end(); t++) {
                inDegrees[*t]--;
                if (inDegrees[*t] == 0) {
                    accessQueue.push(*t);
                }
            }
        }

        return result == org;
    }
};

int main() {
    Solution solution;

    vector<int>         org1  = {1, 2, 3};
    vector<vector<int>> seqs1 = {{1, 2}, {1, 3}};
    cout << solution.sequenceReconstruction(org1, seqs1) << endl;

    vector<int>         org2  = {1, 2, 3};
    vector<vector<int>> seqs2 = {{1, 2}};
    cout << solution.sequenceReconstruction(org2, seqs2) << endl;


    vector<int>         org3  = {1, 2, 3};
    vector<vector<int>> seqs3 = {{1, 2}, {1, 3}, {2, 3}};
    cout << solution.sequenceReconstruction(org3, seqs3) << endl;


    vector<int>         org4  = {4, 1, 5, 2, 6, 3};
    vector<vector<int>> seqs4 = {{5, 2, 6, 3}, {4, 1, 5, 2}};
    cout << solution.sequenceReconstruction(org4, seqs4) << endl;
    return 0;
}
