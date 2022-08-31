#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
private:
    int isTerm[10004];

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        int n = graph.size();
        for (int i = 0; i < n; i++) {
            if (graph[i].size() == 0) {
                isTerm[i] = 1;
            } else {
                isTerm[i] = 0;
            }
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (checker(i, graph)) {
                res.push_back(i);
            }
        }
        return res;
    }
    bool checker(int i, vector<vector<int>>& v)
    {
        if (isTerm[i] == 1)
            return true;
        if (isTerm[i] == -1)
            return false;
        isTerm[i] = -1;
        for (int j = 0; j < v[i].size(); j++) {
            if (!checker(v[i][j], v)) {
                return false;
            }
        }
        isTerm[i] = 1;
        return true;
    }
};
int main(void)
{
    Solution s;
    vector<vector<int>> graph = { { 1, 2 }, { 2, 3 }, { 5 }, { 0 }, { 5 }, {}, {} };
    s.eventualSafeNodes(graph);
    return 0;
}