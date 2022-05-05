#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        vector<int> roots(strs.size());
        for (int i = 0; i < strs.size(); i++) {
            roots[i] = i;
        }


        int graphNum = strs.size();

        for (int i = 0; i < strs.size(); i++) {
            for (int j = i + 1; j < strs.size(); j++) {
                if (isSimilar(strs[i], strs[j]) && mergeGraph(roots, i, j)) {
                    graphNum--;
                }
            }
        }


        return graphNum;
    }

    bool isSimilar(string& a, string& b) {
        int diffNum = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                diffNum++;
            }
        }
        return diffNum == 2 || diffNum == 0;
    }

    bool mergeGraph(vector<int>& roots, int i, int j) {
        int rootI = findRoot(roots, i);
        int rootJ = findRoot(roots, j);

        if (rootI != rootJ) {
            roots[rootI] = rootJ;
            return true;
        }

        return false;
    }

    int findRoot(vector<int>& roots, int i) {
        if (i != roots[i]) {
            roots[i] = findRoot(roots, roots[i]);
        }
        return roots[i];
    }
};

int main() {
    Solution solution;

    vector<string> strs1 = {"tars", "rats", "arts", "star"};
    cout << solution.numSimilarGroups(strs1) << endl;

    vector<string> strs2 = {"omv", "ovm"};
    cout << solution.numSimilarGroups(strs2) << endl;

    return 0;
}
