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
    int u, v, c;
    cin >> u >> v >> c;
    g[u].push_back(make_pair(v, c));
  }
  vector<int> fc(n + 1, -1);
  // 0 -> didn't visit, 1 -> visit with first color, 2 -> visit all
  vector<int> state(n + 1, 0);
  queue<tuple<int, int, int>> q;
  q.push(make_tuple(1, -1, 0));

  while (not q.empty()) {
    auto [u, c, s] = q.front();
    q.pop();
    if (u == n) {
      cout << s << "\n";
      return 0;
    }
    if (state[u] == 0) {
      fc[u] = c;
      for (const auto& [v, nc] : g[u]) {
        if (nc != c and state[v] != 2) {
          q.push(make_tuple(v, nc, s + 1));
        }
      }
      state[u] = 1;
    } else if (state[u] == 1 and c != fc[u]) {
      for (const auto& [v, nc] : g[u]) {
        if (nc == fc[u] and state[v] != 2) {
          q.push(make_tuple(v, nc, s + 1));
        }
      }
      state[u] = 2;
    }
  }

  cout << "-1\n";
  return 0;
}
