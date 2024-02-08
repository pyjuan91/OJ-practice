#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, a, b;
  cin >> n >> m;
  vector<vector<int>> g(n), rg(n);
  while (m--) {
    cin >> a >> b;
    a--, b--;
    g[a].emplace_back(b);
    rg[b].emplace_back(a);
  }

  int cnt = 0;
  vector<int> order, res(n, 0);
  vector<bool> vis(n, false);
  function<void(int, bool)> kazuha = [&](int u, bool rec) {
    vis[u] = true;
    for (auto& nxt : rec ? g[u] : rg[u]) {
      if (!vis[nxt]) {
        kazuha(nxt, rec);
      }
    }
    if (rec)
      order.emplace_back(u);
    else
      res[u] = cnt;
  };

  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      kazuha(i, true);
    }
  }
  vis.assign(n, false);
  while (!order.empty()) {
    if (!vis[order.back()]) {
      cnt++;
      kazuha(order.back(), false);
    }
    order.pop_back();
  }

  cout << cnt << "\n";
  for (auto& x : res) {
    cout << x << " ";
  }
  cout << "\n";
  return 0;
}
