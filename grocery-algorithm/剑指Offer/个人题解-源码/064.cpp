#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

class MagicDictionary {
private:
    unordered_map<string, int> neighborsMap;
    set<string> originWords;

    vector<string> getAllNeighbors(string word) {
        vector<string> result;
        for(int i=0;i<word.size();i++) {
            string tmp = word;
            tmp[i] = '*';
            result.push_back(tmp);
        }
        return result;
    }

public:
    /** Initialize your data structure here. */
    MagicDictionary() {

    }
    
    void buildDict(vector<string> dictionary) {
        for(auto word:dictionary) {
            auto neighbors = getAllNeighbors(word);
            for(auto neighbor: neighbors) {
                neighborsMap[neighbor] += 1;
            }

            originWords.insert(word);
        }
    }
    
    bool search(string searchWord) {
        auto neighbors = getAllNeighbors(searchWord);

        for(auto neighbor: neighbors) {
            if(neighborsMap[neighbor] > 1) {
                return true;
            } else if (neighborsMap[neighbor] == 1) {
                if(originWords.find(searchWord) == originWords.end()) {
                    return true;
                }
            } else if(neighborsMap[neighbor] == 0) {
                continue;
            }
        }

        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */

// 题解
// https://leetcode-cn.com/problems/US1pGT/solution/offerii064shen-qi-de-zi-dian-by-logilong-4hmn/

int main() {
     MagicDictionary* obj = new MagicDictionary();
     vector<string> dictionary = {};
     obj->buildDict(dictionary);

     cout << obj->search() << endl;


    return 0;
}
