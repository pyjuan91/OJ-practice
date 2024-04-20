#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, u, v;
  cin >> n >> m;
  vector<vector<int>> g(n + 1);
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> components;
  vector<bool> vis(n + 1);
  auto kazuha = [&](auto&& zuha, int u) -> int {
    vis[u] = true;
    int res = 1;
    for (auto v : g[u]) {
      if (!vis[v]) {
        res += zuha(zuha, v);
      }
    }
    return res;
  };
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      components.push_back(kazuha(kazuha, i));
    }
  }
  int res = 0;
  for (auto x : components) {
    if (x == 1) continue;
    res += x * (x - 1) / 2;
  }
  cout << res - m << '\n';
  return 0;
}
