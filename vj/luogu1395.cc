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
  int n, u, v;
  cin >> n;
  vector<vector<int>> g(n + 1);
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> tree_size(n + 1, 1), dist_sum(n + 1, 0);
  auto dfs1 = [&](this auto& self, int u, int p) -> void {
    for (const auto& v : g[u]) {
      if (v != p) {
        self(v, u);
        dist_sum[u] += dist_sum[v] + tree_size[v];
        tree_size[u] += tree_size[v];
      }
    }
  };
  dfs1(1, 0);
  debug(tree_size);
  debug(dist_sum);
  int optimal_node = 1, optimal_sum = dist_sum[1];
  auto dfs2 = [&](this auto& self, int u, int p) -> void {
    dist_sum[p] -= dist_sum[u] + tree_size[u];
    tree_size[p] -= tree_size[u];
    tree_size[u] += tree_size[p];
    dist_sum[u] += dist_sum[p] + tree_size[p];
    debug(u, p);
    debug(dist_sum);
    debug(tree_size);
    if (dist_sum[u] < optimal_sum or
        (dist_sum[u] == optimal_sum and u < optimal_node)) {
      optimal_node = u, optimal_sum = dist_sum[u];
    }
    for (const auto& v : g[u]) {
      if (v != p) self(v, u);
    }
    dist_sum[u] -= dist_sum[p] + tree_size[p];
    tree_size[u] -= tree_size[p];
    tree_size[p] += tree_size[u];
    dist_sum[p] += dist_sum[u] + tree_size[u];
  };
  for (const auto& v : g[1]) {
    dfs2(v, 1);
  }
  cout << optimal_node << " " << optimal_sum << "\n";
  return 0;
}
