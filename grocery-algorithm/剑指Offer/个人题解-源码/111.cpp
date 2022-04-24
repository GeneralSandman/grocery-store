#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,map<string,double>> graph;
        // build graph
        for(int i =0;i<equations.size();i+=1) {
            auto a = equations[i][0];
            auto b = equations[i][1];
            auto value = values[i];
            graph[a][b] = value;
            graph[b][a] = 1/value;
        }

        vector<double> result;

        for(auto query:queries) {
            map<string, bool> visited;
            result.push_back(helper(graph, query[0], query[1], visited));
        }

        return result;
    }

    double helper(map<string,map<string,double >> &graph, string from, string to, map<string, bool> &visited) {
        if(visited.find(from) == visited.end()) {
            return 1;
        }
        visited[from] = true;
        if (from == to) {
            return 1;
        }

        // 没找到这个节点
        auto nextIter = graph.find(from);
        if (nextIter == graph.end()) {
            return -1;
        }

        auto nextNodes= nextIter->second;
        for (auto t = nextNodes.begin(); t != nextNodes.end(); t++) {
            double result = helper(graph, t->first, to, visited);
            if(result == -1) {
                return -1;
            }
            return result * t->second;
        }
        return -1;
    }
};

int main() {
    Solution soluation;

    vector<vector<string>> equations = {
        {"a", "b"},
        {"b", "c"},
    };


    vector<double> values = {2.0, 3.0};

    vector<vector<string>> queries = {
        {"a", "a"},
        {"a", "b"},
        {"b", "a"},

        // {"b", "b"},
        // {"b", "c"},
        // {"c", "b"},

        {"x", "x"},
    };


    vector<double>
        result = soluation.calcEquation(equations, values, queries);

    for (auto t:result) {
        cout << "result " << t << endl;
    }

    return 0;
}
