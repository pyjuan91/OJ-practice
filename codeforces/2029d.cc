#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n, m, u, v;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    vector<unordered_set<int>> g(n + 1);
    vector<int> degree(n + 1);
    for (int i = 0; i < m; i++) {
      cin >> u >> v;
      g[u].insert(v);
      g[v].insert(u);
      degree[u]++;
      degree[v]++;
    }

    vector<array<int, 3>> res;
    for (int i = 1; i <= n; i++) {
      while (degree[i] >= 2) {
        auto it = g[i].begin();
        u = *it;
        it++;
        v = *it;
        res.push_back({ i, u, v });
        degree[i] -= 2;
        g[i].erase(u);
        g[i].erase(v);
        g[u].erase(i);
        g[v].erase(i);
        if (g[u].count(v)) {
          g[u].erase(v);
          g[v].erase(u);
          degree[u] -= 2;
          degree[v] -= 2;
        }
        else {
          g[u].insert(v);
          g[v].insert(u);
        }
      }
    }

    if (count(degree.begin(), degree.end(), 0) == n + 1) {
      cout << res.size() << "\n";
      for (auto& [x, y, z] : res) {
        cout << x << " " << y << " " << z << "\n";
      }
      continue;
    }

    unordered_set<int> link_nodes, single_nodes;
    for (int i = 1; i <= n; i++) {
      if (degree[i] == 1) link_nodes.insert(i);
      else if (degree[i] == 0) single_nodes.insert(i);
    }

    int root = *link_nodes.begin();
    int root_neighbor = *g[root].begin();
    if (link_nodes.size() > 2) {
      auto it = link_nodes.begin();
      u = *it;
      it++;
      v = *it;
      if (v == *g[u].begin()) {
        it++;
        v = *it;
      }
      res.push_back({ u, v, *g[u].begin() });
      link_nodes.erase(u);
      link_nodes.erase(*g[u].begin());
      link_nodes.erase(v);
      link_nodes.erase(*g[v].begin());
      root = v;
      root_neighbor = *g[v].begin();
      while (!link_nodes.empty()) {
        u = *link_nodes.begin();
        res.push_back({ root, u, *g[u].begin() });
        link_nodes.erase(u);
        link_nodes.erase(*g[u].begin());
      }
    }

    while (!single_nodes.empty()) {
      auto it = single_nodes.begin();
      res.push_back({ root, root_neighbor, *it });
      root_neighbor = *it;
      single_nodes.erase(it);
    }

    cout << res.size() << "\n";
    for (auto& [x, y, z] : res) {
      cout << x << " " << y << " " << z << "\n";
    }
  }
  return 0;
}
