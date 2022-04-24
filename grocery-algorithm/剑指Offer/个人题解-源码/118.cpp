#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int nodes = 0;

        for(auto edge: edges) {
            nodes = max(nodes, max(edge[0], edge[1]));
        }

        nodes += 1;

        vector<int> roots(nodes);
        for (int i = 0; i < roots.size();i++) {
            roots[i] = i;
        }

        vector<int> result;

        for(auto edge: edges) {
            if(!mergeGraph(roots, edge[0], edge[1])) {
                return edge;
            }
        }


        return result;
    }


    bool mergeGraph(vector<int>& roots, int i, int j) {
        int rootI = findRoot(roots, i);
        int rootJ = findRoot(roots, j);

        if(rootI == rootJ) {
            return false;
        }

        roots[rootI] = rootJ;
        return true;
    }

    // 低效
    int findRoot1(vector<int>& roots, int i) {
        while(roots[i] != i) {
            roots[i] = roots[roots[i]];
            i        = roots[i];
        }
        return roots[i];
    }

    // 下边这个要比上边的要高效，
    // 因为实现了压缩
    int findRoot(vector<int>& roots, int i) {
        if(roots[i] != i) {
            roots[i] = findRoot(roots, roots[i]);
        }
        return roots[i];
    }
};

int main() {
    Solution solution;

    return 0;
}
