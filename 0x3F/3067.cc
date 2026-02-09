#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges,
                                             int signalSpeed) {
    const int n = edges.size() + 1;
    vector<vector<pair<int,int>>> g(n);
    for (const auto& edge : edges) {
      int u = edge[0], v = edge[1], w = edge[2];
      g[u].emplace_back(v, w);
      g[v].emplace_back(u, w);
    }
    vector<int> res(n);

    for (int root = 0; root < n; root++) {
      vector<bool> vis(n);
      vector<int> cnts;
      vis[root] = true;
      for (const auto& [v, w] : g[root]) {
        int cnt = 0;
        queue<int> nodes, dists;
        nodes.push(v), dists.push(w);
        vis[v] = true;
        while (!nodes.empty()) {
          int cur_node = nodes.front();
          nodes.pop();
          int cur_dist = dists.front();
          dists.pop();
          if (cur_dist % signalSpeed == 0) cnt++;
          for (const auto& [next_node, next_weight] : g[cur_node]) {
            if (!vis[next_node]) {
              vis[next_node] = true;
              nodes.push(next_node);
              dists.push(cur_dist + next_weight);
            }
          }
        }
        cnts.push_back(cnt);
      }
      int prefix = 0;
      for (const auto& x : cnts) {
        res[root] += prefix * x;
        prefix += x;
      }
    }
    return res;
  }
};

int main() { return 0; }