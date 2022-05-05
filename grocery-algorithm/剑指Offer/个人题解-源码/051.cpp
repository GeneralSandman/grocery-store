#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;


struct TreeNode {
    int       val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() :
        val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) :
        val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right) :
        val(x), left(left), right(right) {
    }
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }

    int dfs(TreeNode* root, int& maxSum) {
        if (root == nullptr) {
            return 0;
        }

        int maxSumLeft = INT_MIN;
        int left       = max(0, dfs(root->left, maxSumLeft));


        int maxSumRight = INT_MIN;
        int right       = max(0, dfs(root->right, maxSumRight));


        maxSum = max(maxSum, max(maxSumLeft, maxSumRight));
        maxSum = max(maxSum, root->val + left + right);

        return root->val + max(left, right);
    }
};

int main() {
    Solution solution;

    return 0;
}
