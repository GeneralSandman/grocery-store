#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {

        int circleNum = 0;

        if (isConnected.size() == 0 || isConnected[0].size() == 0)
        {
            return 0;
        }

        int cityNum = isConnected.size();
        map<int, bool> visited;
        for (int i = 0; i < cityNum; i += 1)
        {
            if (visited.find(i) == visited.end())
            {
                helper(isConnected, visited, cityNum, i);
                circleNum += 1;
            }
        }

        return circleNum;
    }

    int helper(vector<vector<int>> &isConnected, map<int, bool> &visited, int cityNum, int i)
    {
        queue<int> accessQueue;
        accessQueue.push(i);

        while (accessQueue.size() != 0)
        {
            int tmp = accessQueue.front();
            accessQueue.pop();
            visited[tmp] = true;


            for (int n = 0; n < cityNum; n += 1)
            {
                if (isConnected[tmp][n] == 0) {
                    continue;
                }
                if (visited.find(n) != visited.end())
                {
                    continue;
                }

                accessQueue.push(n);
            }
        }

        return 0;
    }
};

// 并查集
class Solution1 {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> roots(isConnected.size(), 0);
        for (int i = 0; i < isConnected.size(); i++) {
            roots[i] = i;
        }


        int result = isConnected.size();

        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = i + 1; j < isConnected.size(); j++) {
                if(isConnected[i][j]) {
                    if(mergeGraph(roots, i, j)) {
                        result--;
                    }
                }
            }
        }



        return result;
    }

    bool mergeGraph(vector<int> &roots, int i, int j) {
        int rootI = findRoot(roots, i);
        int rootJ = findRoot(roots, j);

        // 合并过去
        if(rootI != rootJ) {
            roots[rootI] = rootJ;
            return true;
        }
        return false;
    }

    int findRoot(vector<int> &roots, int i) {
        if(roots[i] != i) {
            roots[i] = findRoot(roots, roots[i]);
        }
        return roots[i];
    }
};

int main()
{
    Solution s;
    Solution1 s1;

    vector<vector<int>> isConnected1 = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1},
    };
    cout << s.findCircleNum(isConnected1) << endl;
    cout << s1.findCircleNum(isConnected1) << endl;



    vector<vector<int>> isConnected2 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1},
    };
    cout << s.findCircleNum(isConnected2) << endl;
    cout << s1.findCircleNum(isConnected2) << endl;

    vector<vector<int>> isConnected3 = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1},
    };
    cout << s.findCircleNum(isConnected3) << endl;
    cout << s1.findCircleNum(isConnected3) << endl;

    return 0;
}
