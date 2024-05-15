#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n, m, k, u, v;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vector<int> subtree_size(n + 1, 1);
    function<void(int, int)> dfs1 = [&](int u, int p) {
      for (int v : adj[u]) {
        if (v == p) continue;
        dfs1(v, u);
        subtree_size[u] += subtree_size[v];
      }
    };

    int res = INT64_MAX;
    function<void(int, int)> dfs2 = [&](int u, int p) {
      for (int v : adj[u]) {
        if (v == p) continue;
        int x = subtree_size[v];
        res = min(res, x * x + (n - x) * (n - x));
        dfs2(v, u);
      }
    };

    dfs1(1, 0);
    dfs2(1, 0);
    cout << res << '\n';
  }
  return 0;
}
