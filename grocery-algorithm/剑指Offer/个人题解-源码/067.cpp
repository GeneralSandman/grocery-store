#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string.h>
#include <set>

using namespace std;

class Solution {
    class TrieNode {
        public:
            TrieNode *childern[2];
            TrieNode() {
                memset(childern, 0, sizeof(childern));
            }
    };

    private:
        TrieNode *root;

        void buildTrieNode(vector<int> &nums) {
            root = new TrieNode();

            for (auto num : nums)
            {
                TrieNode *current = root;
                for (int i = 0; i < 32;i++) {
                    int index = (num >> i) & 1;
                    if (current->childern[index] == nullptr)
                    {
                        current->childern[index] = new TrieNode();
                    }
                    current = current->childern[index];
                }
            }
        }

public:
    int findMaximumXOR(vector<int>& nums) {
        buildTrieNode(nums);

        int result = 0;

        for (auto num : nums){
            TrieNode *current = root;
            int tmp = 0;
            for (int i = 0; i < 32; i++)
            {
                int index = (num >> i) & 1;
                index = (index == 0) ? 1 : 0;
                if (current->childern[index] == nullptr)
                {
                    current->childern[index] = new TrieNode();
                } else {
                    
                }
                current = current->childern[index];
            }

            result = max(result, tmp);
        }

        return result;
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {3,10,5,25,2,8};
    cout << solution.findMaximumXOR(nums1) << endl;

    vector<int> nums2 = {0};
    cout << solution.findMaximumXOR(nums2) << endl;

    vector<int> nums3 = {2,4};
    cout << solution.findMaximumXOR(nums3) << endl;

    vector<int> nums4 = {8,10,2};
    cout << solution.findMaximumXOR(nums4) << endl;

    vector<int> nums5 = {14,70,53,83,49,91,36,80,92,51,66,70};
    cout << solution.findMaximumXOR(nums5) << endl;

    return 0;
}
