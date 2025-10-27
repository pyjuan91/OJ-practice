#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        int n = graph.size();
        vector<vector<int>> res;
        vector<int> route = { 0 };
        auto dfs = [&](this auto& self, int u) -> void {
            if (u == n - 1)
            {
                res.push_back(route);
                return;
            }
            for (const auto& v : graph[u])
            {
                route.push_back(v);
                self(v);
                route.pop_back();
            }
        };
        dfs(0);
        return res;
    }
};

int main()
{
    return 0;
}