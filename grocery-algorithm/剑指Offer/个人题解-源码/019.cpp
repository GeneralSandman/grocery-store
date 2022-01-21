#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        if(s.empty()) {
            return false;
        }

        int begin = 0;
        int end = s.size()-1;
        while(begin<=end) {
            if(s[begin] != s[end]){
                break;
            }
            begin++;
            end--;
        }

        return isPalindrome(s,begin+1,end) || isPalindrome(s,begin,end-1);

    }

    bool isPalindrome(string s, int begin, int end) {
        while(begin<=end) {
            if(s[begin] != s[end]) {
                return false;
            }
            begin ++;
            end --;
        }
        return true;
    }
};


class Solution2 {
public:
    bool validPalindrome(string s) {
        if(s.empty()) {
            return false;
        }

        int begin = 0;
        int end = s.size()-1;

        bool hasDeleted = false;

        while(begin<=end) {
            char tmpA = s[begin];
            char tmpB = s[end];

            if(tmpA == tmpB){
                begin ++;
                end --;
                continue;
            }

            if(hasDeleted) {
                return false;
            }

            if(s[begin] == s[end-1]) {
                end--;
                hasDeleted = true;
            } else if(s[begin+1]== s[end]) {
                begin++;
                hasDeleted = true;
            } else {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution solution;

    cout << solution.validPalindrome("abcba") << endl;
    cout << solution.validPalindrome("abca") << endl;
    cout << solution.validPalindrome("aca") << endl;

    cout << solution.validPalindrome("abc") << endl;

    cout << solution.validPalindrome("abcdcba") << endl;
    cout << solution.validPalindrome("abcdcbag") << endl;

    cout << solution.validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga") << endl;
    cout << solution.validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuclmgmqfvnbgtapekouga") << endl;


    return 0;
}
