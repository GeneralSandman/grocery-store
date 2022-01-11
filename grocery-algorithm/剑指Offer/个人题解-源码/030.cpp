#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class RandomizedSet {
private:
    unordered_map<int, int> hashTable; // value --> index
    vector<int> data; // index,value
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hashTable.find(val) != hashTable.end()) {
            return false;
        }
        hashTable[val] = data.size();
        data.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto iter = hashTable.find(val);
        if(iter == hashTable.end()) {
            return false;
        }

        int aIndex = hashTable[val];
        int bIndex = data.size()-1;
        data[aIndex] = data[bIndex];

        hashTable[val] = bIndex;
        hashTable[data[aIndex]] = aIndex;
        
        data.erase(data.end()-1);
        hashTable.erase(iter);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        // srand((unsigned)time(NULL));
        int idx = rand() % (int)data.size();
        return data[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {
    Solution solution;

    return 0;
}
