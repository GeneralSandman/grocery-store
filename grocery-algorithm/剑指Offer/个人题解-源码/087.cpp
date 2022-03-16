#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
private:
    void helper(string &s, int begin, vector<string> ip_segment, int ip_segment_index, vector<string> &result) {

        if(isValidIpSegment(ip_segment[ip_segment_index] + s[begin])) {
            ip_segment[ip_segment_index] += s[begin];
        }

        if(ip_segment_index<3 && ip_segment[ip_segment_index+1] )

        

        ip_segment[ip_segment_index + 1] += s[begin];
    }

    bool isValidIpSegment(string s) {
        int int_value = atoi(s.c_str());
        return (s == "0" || s[0] != '0') && int_value <= 255;
    }

    string formatIp(vector<string> &ip_segment) {
        string result;

        result = ip_segment[0] + '.' +
            ip_segment[1] + '.' +
            ip_segment[2] + '.' +
            ip_segment[3];

        return result;
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ip_segment(4);
        vector<string> result;
        helper(s, 0, ip_segment, 0, result);
        return result;
    }
};

int main() {
    Solution s;

    return 0;
}
