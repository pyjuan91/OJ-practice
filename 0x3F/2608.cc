#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int findShortestCycle(int n, vector<vector<int>>& edges)
    {
        const int m = edges.size();
        vector<vector<pair<int, int>>> g(n);
        for(int i = 0; i < m; i++)
        {
            int u = edges[i][0], v = edges[i][1];
            g[u].push_back(make_pair(v, i));
            g[v].push_back(make_pair(u, i));
        }
        const int kInf = numeric_limits<int>::max();
        int res        = kInf;

        for(int i = 0; i < n; i++)
        {
            auto bfs = [&](int u) -> int {
                queue<int> q;
                q.push(u);
                vector<int> dist(n);
                vector<bool> vis_node(n), vis_edge(m);
                vis_node[u] = true;
                int cycle_len = kInf;
                while(!q.empty())
                {
                    int u = q.front();
                    q.pop();
                    int d = dist[u];

                    for(const auto& [v, id] : g[u])
                    {
                        if(!vis_edge[id])
                        {
                            vis_edge[id] = true;
                            if(vis_node[v])
                                cycle_len = min(cycle_len, dist[v] + d + 1);
                            else
                            {
                                vis_node[v] = true;
                                q.push(v);
                                dist[v] = d + 1;
                            }
                        }
                    }
                }
                return cycle_len;
            };
            res = min(res, bfs(i));
        }

        return res == kInf ? -1 : res;
    }
};

int main() { return 0; }