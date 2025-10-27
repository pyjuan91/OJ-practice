#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        vector g(n, vector<int>());
        for (const auto& edge: edges) {
            int u = edge[0], v = edge[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<bool> vis(n, false);
        vis[source] = true;
        auto dfs = [&](this auto& self, int u) -> bool {
            if (u == destination) return true;
            for (const auto& v: g[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    if (self(v)) return true;
                }
            }
            return false;
        };

        return dfs(source);
    }
};

int main()
{
    return 0;
}