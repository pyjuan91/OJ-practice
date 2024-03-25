#include <bits/stdc++.h>
using namespace std;

const int kMax = 1e5 + 5;
int n, m, u, v, dfn[kMax], low[kMax], dfn_cnt;
vector<pair<int, int>> ans, g[kMax];

void tarjan(int u, int p_id) {
  dfn[u] = low[u] = ++dfn_cnt;
  for (auto [v, id] : g[u]) {
    if (id == (p_id ^ 1)) continue;
    if (!dfn[v]) {
      tarjan(v, id);
      low[u] = min(low[u], low[v]);
      if (low[v] > dfn[u]) ans.push_back({u, v});
    } else {
      low[u] = min(low[u], dfn[v]);
    }
  }
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    g[u].push_back({v, i << 1});
    g[v].push_back({u, i << 1 | 1});
  }
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) tarjan(i, 0);
  }
  cout << ans.size() << '\n';
  for (auto [u, v] : ans) cout << u << ' ' << v << '\n';
  return 0;
}
