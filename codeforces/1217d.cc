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
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(make_pair(v, i));
  }

  vector<int> color(n + 1);
  bool has_cycle = false;
  vector<int> edge_color(m, 1);

  auto dfs = [&](this auto self, int u) -> void {
    color[u] = 1;
    for (const auto& [v, i] : g[u]) {
      if (color[v] == 1) {
        edge_color[i] = 2;
        has_cycle = true;
      } else if (color[v] == 0) {
        self(v);
      }
    }
    color[u] = 2;
  };

  for (int i = 1; i <= n; i++) dfs(i);

  cout << (has_cycle ? 2 : 1) << "\n";
  for (const auto& x : edge_color) cout << x << " ";

  return 0;
}
