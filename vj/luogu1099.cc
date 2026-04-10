#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, s;
  cin >> n >> s;
  vector<vector<pair<int, int>>> g(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back(make_pair(v, w));
    g[v].push_back(make_pair(u, w));
  }
  vector<int> dist1(n + 1, 0), parent(n + 1, 0);
  auto dfs1 = [&](this auto& self, vector<int>& dist, vector<int>& parent,
                  int u, int p) -> void {
    for (const auto& [v, w] : g[u]) {
      if (v != p) {
        dist[v] = dist[u] + w;
        parent[v] = u;
        self(dist, parent, v, u);
      }
    }
  };
  dfs1(dist1, parent, 1, 0);
  int diameter_endpoint1 = 1;
  for (int i = 1; i <= n; i++) {
    if (dist1[i] > dist1[diameter_endpoint1]) {
      diameter_endpoint1 = i;
    }
  }
  dist1.assign(n + 1, 0);
  parent.assign(n + 1, 0);
  dfs1(dist1, parent, diameter_endpoint1, 0);
  int diameter_endpoint2 = diameter_endpoint1;
  for (int i = 1; i <= n; i++) {
    if (dist1[i] > dist1[diameter_endpoint2]) {
      diameter_endpoint2 = i;
    }
  }
  debug(diameter_endpoint1, diameter_endpoint2);
  deque<int> cores = {diameter_endpoint2};
  int res = dist1[diameter_endpoint2];
  int core_size = 0;
  for (int u = diameter_endpoint2; parent[u] != 0; u = parent[u]) {
    core_size += dist1[u] - dist1[parent[u]];
    cores.push_back(parent[u]);
    while (core_size > s) {
      core_size -= dist1[cores[0]] - dist1[cores[1]];
      cores.pop_front();
    }
    debug(u, cores);
    // multi-starting point bfs
    queue<int> nodes, dists;
    vector<bool> vis(n + 1, false);
    for (const auto& x : cores) {
      nodes.push(x), dists.push(0);
      vis[x] = true;
    }
    int ecc = 0;
    while (!nodes.empty()) {
      int u = nodes.front(), d = dists.front();
      debug(u, d);
      nodes.pop(), dists.pop();
      for (const auto& [v, w] : g[u]) {
        if (not vis[v]) {
          vis[v] = true;
          ecc = max(ecc, d + w);
          nodes.push(v), dists.push(d + w);
        }
      }
    }
    debug(ecc);
    res = min(res, ecc);
  }
  cout << res << "\n";
  return 0;
}
