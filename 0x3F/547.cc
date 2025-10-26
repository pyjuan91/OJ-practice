#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        size_t n = isConnected.size();
        int res = 0;

        vector<bool> vis(n, false);
        auto dfs = [&](auto&& self, int u) -> void {
            vis[u] = true;
            for (size_t i = 0; i < n; i++) {
                if (!vis[i] && isConnected[u][i]) {
                    self(self, i);
                }
            }
        };

        for (size_t i = 0; i < n; i++) {
            if (!vis[i]) {
                res++;
                dfs(dfs, i);
            }
        }
        
        return res;
    }
};

int main()
{
    return 0;
}