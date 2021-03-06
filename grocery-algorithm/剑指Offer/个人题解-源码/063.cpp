#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        if (dictionary.empty() || sentence.size() == 0) {
            return "";
        }

        // build
        map<string, bool> hashTable;
        for (auto word : dictionary) {
            hashTable[word] = true;
        }

        //
        vector<string> resultWords;

        string tmp;
        for (auto ch : sentence) {
            if (ch == ' ') {
                if (tmp.size()) {
                    auto word = helper(hashTable, tmp);
                    resultWords.push_back(word);
                }
                tmp.clear();
                continue;
            }

            tmp += ch;
        }

        if (tmp.size()) {
            auto word = helper(hashTable, tmp);
            resultWords.push_back(word);
        }

        string result;
        for (int i = 0; i < resultWords.size(); i++) {
            result += resultWords[i];
            if (i != resultWords.size() - 1) {
                result += " ";
            }
        }

        return result;
    }

    string helper(map<string, bool>& hashTable, string word) {
        string tmp;
        for (auto ch : word) {
            tmp += ch;
            if (hashTable.end() != hashTable.find(tmp)) {
                return tmp;
            }
        }
        return word;
    }
};

int main() {
    Solution s;

    vector<string> dictionary1 = {"cat", "bat", "rat"};
    string         sentence1   = "the cattle was rattled by the battery";
    cout << s.replaceWords(dictionary1, sentence1) << endl;

    vector<string> dictionary2 = {"a", "b", "c"};
    string         sentence2   = "aadsfasf absbs bbab cadsfafs";
    cout << s.replaceWords(dictionary2, sentence2) << endl;

    vector<string> dictionary3 = {"a", "aa", "aaa", "aaaa"};
    string         sentence3   = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa";
    cout << s.replaceWords(dictionary3, sentence3) << endl;

    return 0;
}
