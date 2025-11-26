#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int>
    shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges)
    {
        vector<vector<pair<int, int>>> g(n);
        for(const auto& red_edge : redEdges)
        {
            int u = red_edge[0], v = red_edge[1];
            g[u].emplace_back(v, 0);
        }
        for(const auto& blue_edge : blueEdges)
        {
            int u = blue_edge[0], v = blue_edge[1];
            g[u].emplace_back(v, 1);
        }

        vector<vector<int>> dist(n, vector<int>(2, INT32_MAX));
        dist[0][0] = dist[0][1] = 0;
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0)), q.push(make_pair(0, 1));

        while(!q.empty())
        {
            auto [u, c] = q.front();
            q.pop();
            for(const auto& [v, color] : g[u])
            {
                if(color != c && dist[v][color] == INT32_MAX)
                {
                    dist[v][color] = dist[u][c] + 1;
                    q.push(make_pair(v, color));
                }
            }
        }

        vector<int> res;
        for(int i = 0; i < n; i++)
        {
            int shortest = min(dist[i][0], dist[i][1]);
            if(shortest == INT32_MAX)
                res.push_back(-1);
            else
                res.push_back(shortest);
        }
        return res;
    }
};

int main() { return 0; }