#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, set<char>> graph;
        unordered_map<char, int>       graphInDegress;

        for (auto word : words) {
            for (auto ch : word) {
                graph[ch]          = set<char>();
                graphInDegress[ch] = 0;
            }
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];
            if (startsWith(word1, word2) && word1 != word2) {
                return "";
            }

            for (int j = 0; j < min(word1.size(), word2.size()); j++) {
                char ch1 = word1[j];
                char ch2 = word2[j];
                if (ch1 != ch2) {
                    auto iter    = graph.find(ch1);
                    auto tmp_set = iter->second;
                    if (tmp_set.find(ch2) == tmp_set.end()) {
                        graph[ch1].insert(ch2);
                        graphInDegress[ch2] += 1;
                    }
                    break;
                }
            }
        }

        // debug
        // cout << "--------" << endl;
        // for (auto iter = graph.begin(); iter != graph.end(); iter++) {
        //     for (auto iterr = iter->second.begin(); iterr != iter->second.end(); iterr++) {
        //         cout << iter->first << " " << *iterr << endl;
        //     }
        //     cout << endl;
        // }
        // debug


        // 拓扑排序
        // 广度优先搜索
        // 逐步降低入度


        queue<char> accessQueue;
        for (auto iter = graphInDegress.begin(); iter != graphInDegress.end(); iter++) {
            if (iter->second == 0) {
                accessQueue.push(iter->first);
            }
        }

        string result;
        while (accessQueue.size()) {
            char next = accessQueue.front();
            accessQueue.pop();

            result += next;

            auto iter    = graph.find(next);
            auto tmp_set = iter->second;
            for (auto iterr = tmp_set.begin(); iterr != tmp_set.end(); iterr++) {
                graphInDegress[*iterr]--;
                if (graphInDegress[*iterr] == 0) {
                    accessQueue.push(*iterr);
                }
            }
        }


        if (result.size() == graphInDegress.size()) {
            return result;
        }
        return "";
    }

    bool startsWith(const std::string& str, const std::string prefix) {
        return (str.rfind(prefix, 0) == 0);
    }
};

int main() {
    Solution solution;

    vector<string> words1 = {"abc", "ab"};
    cout << "result:" << solution.alienOrder(words1) << endl;

    vector<string> words2 = {"ac", "ab", "bc", "zc", "zb"};
    cout << "result:" << solution.alienOrder(words2) << endl;

    vector<string> words3 = {"wrt", "wrf", "er", "ett", "rftt"};
    cout << "result:" << solution.alienOrder(words3) << endl;

    vector<string> words4 = {"z", "x"};
    cout << "result:" << solution.alienOrder(words4) << endl;

    vector<string> words5 = {"z", "x", "z"};
    cout << "result:" << solution.alienOrder(words5) << endl;

    return 0;
}

