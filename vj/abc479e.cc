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
  int n, u, v, k;
  cin >> n;
  vector<vector<pair<int, int>>> g(n + 1);
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(make_pair(v, i));
    g[v].push_back(make_pair(u, i));
  }
  vector<int> sz(n + 1);
  auto dfs1 = [&](this auto& dfs, int cur_node, int parent_node) -> void {
    sz[cur_node] = 1;
    for (const auto& [child_node, edge_id] : g[cur_node]) {
      if (child_node != parent_node) {
        dfs(child_node, cur_node);
        sz[cur_node] += sz[child_node];
      }
    }
  };
  dfs1(1, 0);
  debug(sz);
  vector<int> mx(n + 1);
  auto dfs2 = [&](this auto& dfs, int cur_node, int parent_node) -> void {
    mx[cur_node] = n - sz[cur_node];
    for (const auto& [child_node, edge_id] : g[cur_node]) {
      if (child_node != parent_node) {
        mx[cur_node] = max(mx[cur_node], sz[child_node]);
        dfs(child_node, cur_node);
      }
    }
  };
  dfs2(1, 0);
  debug(mx);
  int centroid = 0;
  for (int i = 1; i <= n; i++)
    if (mx[i] <= n / 2) centroid = i;
  debug(centroid);

  vector<int> res(n + 1);
  auto dfs3 = [&](this auto& dfs, int cur_node, int parent_node) -> void {
    for (const auto& [child_node, edge_id] : g[cur_node]) {
      if (child_node != parent_node) {
        res[child_node] += res[cur_node] + edge_id;
        dfs(child_node, cur_node);
      }
    }
  };
  dfs3(centroid, 0);
  int sum = n * (n - 1) / 2;
  for (int i = 1; i <= n; i++) cout << sum - res[i] << " ";
  cout << "\n";
  return 0;
}
