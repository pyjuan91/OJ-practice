#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
using namespace std;

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int _ = [] {
      int n, u, v;
      cin >> n;
      vector<vector<int>> g(n + 1);
      for (int i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
      }
      // check if its a sunflower
      for (int i = 1; i <= n; i++) {
        if (g[i].size() == n - 1) {
          for (int j = 1, x = 6; j <= n; j++) {
            if (j == i)
              cout << 2 << " ";
            else {
              if (x > 2 * n)
                cout << "1 ";
              else
                cout << x << " ";
              x += 2;
            }
          }
          cout << "\n";
          return 0;
        }
      }
      vector<int> color(n + 1);
      vector<vector<int>> nodes_with_color(2);
      vector<int> parent(n + 1);
      parent[1] = 1;
      queue<int> q;
      q.push(1);
      color[1] = 1;
      nodes_with_color[1].push_back(1);
      vector<int> bfs_order;
      while (!q.empty()) {
        int u = q.front();
        bfs_order.push_back(u);
        q.pop();
        for (int v : g[u]) {
          if (parent[v] == 0) {
            parent[v] = u;
            color[v] = 1 ^ color[u];
            nodes_with_color[color[v]].push_back(v);
            q.push(v);
          }
        }
      }

      debug(bfs_order);
      vector<int> res(n + 1);
      int white = 2, black = 2 * n;
      for (const auto& x : bfs_order) {
        if (color[x] == 0) {
          if (res[parent[x]] - white == 2) white++;
          res[x] = white;
          white += 2;
        } else {
          if (black - res[parent[x]] == 2) black--;
          res[x] = black;
          black -= 2;
        }
        debug(x, res[x], color[x], parent[x]);
      }
      for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
      }
      cout << "\n";
      return 0;
    }();
  }
  return 0;
}
