#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

int patty(int n, int m, vector<vector<pair<int, int>>>& g) {
  if (n % 2) return -1;
  vector<int> relative_val(n + 1);
  vector<bool> vis(n + 1, false);
  deque<int> q = {1};
  vis[1] = true;
  while (!q.empty()) {
    int u = q.front();
    int u_val = relative_val[u];
    q.pop_front();
    for (const auto& [v, w] : g[u]) {
      if (!vis[v]) {
        vis[v] = true;
        relative_val[v] = u_val xor w;
        q.push_back(v);
      }
    }
  }
  int tot = 0;
  for (int i = 1; i <= n; i++) tot = tot xor i xor relative_val[i];
  return tot;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      g[u].push_back(make_pair(v, w));
      g[v].push_back(make_pair(u, w));
    }
    cout << patty(n, m, g) << "\n";
  }
  return 0;
}
