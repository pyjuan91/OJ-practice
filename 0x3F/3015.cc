#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> countOfPairs(int n, int x, int y)
    {
        vector<vector<int>> g(n);
        for(int i = 1; i < n; i++)
        {
            g[i].push_back(i - 1);
            g[i - 1].push_back(i);
        }
        g[x - 1].push_back(y - 1), g[y - 1].push_back(x - 1);

        auto bfs = [&](int start) -> vector<int> {
            vector<int> dist(n);
            vector<bool> vis(n);
            queue<int> q;
            q.push(start);
            vis[start] = true;
            while(!q.empty())
            {
                int u = q.front();
                q.pop();
                for(const auto& v : g[u])
                {
                    if(!vis[v])
                    {
                        vis[v] = true;
                        q.push(v);
                        dist[v] = dist[u] + 1;
                    }
                }
            }
            return dist;
        };

        vector<int> res(n);
        for(int source = 0; source < n; source++)
        {
            auto dist = bfs(source);
            for(int desti = 0; desti < n; desti++)
            {
                if(desti != source)
                    res[dist[desti] - 1]++;
            }
        }
        return res;
    }
};

int main() { return 0; }