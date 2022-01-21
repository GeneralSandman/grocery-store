#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        if (s.empty())
        {
            return false;
        }

        int begin = 0;
        int end = s.size() - 1;

        while (begin <= end)
        {
            char tmpA = isNumberAndChar(s[begin]);
            char tmpB = isNumberAndChar(s[end]);

            if(tmpA==' ') {
                begin++;
                continue;
            }

            if(tmpB==' ') {
                end--;
                continue;
            }

            if(tmpA != tmpB) {
                return false;
            }
            begin ++;
            end --;
        }

        return true;
    }

private:
    char isNumberAndChar(char ch)
    {

        if (('0' <= ch && ch <= '9') || ('a' <= ch && ch <= 'z'))
        {
            return ch;
        }
        else if ('A' <= ch && ch <= 'Z')
        {
            return 'a' + ch - 'A';
        } else {
            return ' ';
        }
    };

};

int main()
{
    Solution solution;

    cout << solution.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << solution.isPalindrome("race e car") << endl;
    cout << solution.isPalindrome("race a car") << endl;

    return 0;
}
