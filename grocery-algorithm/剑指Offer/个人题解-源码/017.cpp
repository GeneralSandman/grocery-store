#include <iostream>
#include <vector>
#include <map>

using namespace std;

// https://leetcode-cn.com/problems/M1oyTv/solution/c-zi-ren-wei-gai-fang-fa-bi-yuan-shu-hao-2x4l/
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hashTableS(256, 0);
        vector<int> hashTableT(256, 0);
        string result;

        for(auto ch:t) {
            hashTableT[ch]++;
        }

        int left = 0;
        int right = 0;

        int target = 0;

        for (; right < s.size();right++)
        {
            hashTableS[s[right]]++;
            
            //在找到第一个符合条件的窗口后，这个语句不会再运行了。
            //ps.该语句的作用是统计窗口内的有效字符
            if(hashTableS[s[right]] <= hashTableT[s[right]]) {
                target++;
            }

            while(hashTableS[s[left]] > hashTableT[s[left]]) { // 左边的这个字符不在目标字符串中，可以放心的移除，
                hashTableS[s[left]]--;
                left++;
            }

            if(target != t.size()) {
                continue;
            }
            if(result.empty() || right-left+1 < result.size()) {
                result = s.substr(left, right-left+1);
            }
        }

        return result;
    }
};


int main() {
    Solution s;

    cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;

    return 0;
}
