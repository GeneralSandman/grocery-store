#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> access;

        if(tokens.empty()) {
            return 0;
        }

        for(string token : tokens) {
            if(token == "+") {
                int b = access.top(); access.pop();
                int a = access.top(); access.pop();
                access.push(a+b);
            } else if(token == "-") {
                int b = access.top(); access.pop();
                int a = access.top(); access.pop();
                access.push(a-b);
            } else if(token == "*") {
                int b = access.top(); access.pop();
                int a = access.top(); access.pop();
                access.push(a*b);
            } else if(token == "/") {
                int b = access.top(); access.pop();
                int a = access.top(); access.pop();
                access.push(a/b);
            } else {
                access.push(atoi(token.c_str()));
            }
        }


        return access.top();
    }
};

int main() {
    Solution s;

    vector<string> tmp1 = {"2","1","+","3","*"};
    cout << s.evalRPN(tmp1) << endl;

    vector<string> tmp2 = {"4","13","5","/","+"};
    cout << s.evalRPN(tmp2) << endl;

    vector<string> tmp3 = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << s.evalRPN(tmp3) << endl;

    return 0;
}
