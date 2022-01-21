#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.empty() || b.empty()) {
            return "";
        }

        int i = a.size()-1;
        int j = b.size()-1;

        int carry = 0;
        string result;
        while(i>=0||j>=0)  {
            if(i>=0) {
                carry += a[i]-'0';
                i--;
            }

            if(j>=0) {
                carry += b[j]-'0';
                j--;
            }


            result = char('0' + carry%2) + result;
            carry /= 2;

        }

        if(carry) {
            result = char('0' + carry) + result;
        }


        return result;
    }
};

int main() {
    Solution solution;

    cout << solution.addBinary("11", "10") << endl;
    cout << solution.addBinary("1010", "1011") << endl;

    return 0;
}
