#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  while (cin >> n && n) {
    vector<vector<int>> g(n + 1);
    string s;
    cin.ignore();
    while (getline(cin, s) && s != "0") {
      stringstream ss(s);
      int u, v;
      ss >> u;
      while (ss >> v) {
        g[u].push_back(v);
        g[v].push_back(u);
      }
    }
    if (n < 3) {
      cout << 0 << '\n';
      continue;
    }
    auto is_critical = [&](int cri) {
      vector<bool> vis(n + 1, false);
      queue<int> q;
      if (cri == 1)
        q.push(2);
      else
        q.push(1);
      vis[q.front()] = true;
      vis[cri] = true;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
          if (!vis[v]) {
            vis[v] = true;
            q.push(v);
          }
        }
      }
      for (int i = 1; i <= n; i++) {
        if (!vis[i]) return false;
      }
      return true;
    };
    int res = 0;
    for (int i = 1; i <= n; i++) {
      if (!is_critical(i)) {
        res++;
      }
    }
    cout << res << '\n';
  }
  return 0;
}
