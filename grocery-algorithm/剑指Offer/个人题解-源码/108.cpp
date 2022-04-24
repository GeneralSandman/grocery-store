#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> wordListTable;
        for (int i = 0; i < wordList.size();i++) {
            wordListTable.insert(wordList[i]);
        }

        unordered_map<string, vector<string> > dependence;

        vector<string> newWordList = wordList;
        newWordList.push_back(beginWord);
        for (string word: newWordList) {
            string origin = word;
            string tmp = word;
            for (int j = 0; j < tmp.size();j++) {
                for (char k = 'a'; k <= 'z'; k++) {
                    char old = tmp[j];
                    if (tmp[j] != k) {
                        tmp[j] = k;
                        if(wordListTable.find(tmp) != wordListTable.end()) {
                            dependence[origin].push_back(tmp);
                        }
                        tmp[j] = old;
                    }
                }
            }
        }



        // for (auto iter = dependence.begin(); iter != dependence.end();iter++) {
        //     cout << iter->first << " -> ";
        //     for (auto w : iter->second) {
        //         cout << w << " ";
        //     }
        //     cout << endl;
        // }


        queue<string> q1;
        queue<string> q2;


        q1.push(beginWord);
        int length = 2;
        while (!q1.empty()) {

            string first = q1.front();
            q1.pop();

            auto iter = dependence.find(first);
            if(iter != dependence.end()) {
                for(string next : iter->second) {
                    if(wordListTable.find(next) != wordListTable.end()) {
                        q2.push(next);
                        wordListTable.erase(next);
                    }
                    if(next == endWord) {
                        return length;
                    }

                }
            }
            

            if (q1.empty()) {
                swap(q1, q2);
                length++;
            }
        }

        return 0;
    }
};

int main() {
    Solution solution;

    vector<string> wordList1 = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << solution.ladderLength("hit", "cog", wordList1) << endl;
    cout << solution.ladderLength("hit", "cox", wordList1) << endl;


    vector<string> wordList2 = {"hot", "dog"};
    cout << solution.ladderLength("hot", "dog", wordList2) << endl;
    cout << solution.ladderLength("hit", "dog", wordList2) << endl;
    

    return 0;
}
