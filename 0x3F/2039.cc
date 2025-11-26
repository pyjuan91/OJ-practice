#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience)
    {
        int n = patience.size();
        vector<vector<int>> g(n);
        for(const auto& edge : edges)
        {
            int u = edge[0], v = edge[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> dist(n, INT32_MAX);
        dist[0] = 0;
        queue<int> q;
        q.push(0);

        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(const auto& v : g[u])
            {
                if(dist[v] == INT32_MAX)
                {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        int res = 0;
        for(int i = 1; i < n; i++)
        {
            int len = dist[i];
            int tot = 1 + (2 * len - 1) / patience[i];
            res     = max(res, (tot - 1) * patience[i] + 2 * len + 1);
        }

        return res;
    }
};

int main() { return 0; }