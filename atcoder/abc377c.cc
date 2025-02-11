#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, u, v;
  set<pair<int, int>> s;

  auto zuha = [&](int u, int v) {
    const int dx[] = { 1, 1, -1, -1, 2, 2, -2, -2 };
    const int dy[] = { 2, -2, 2, -2, 1, -1, 1, -1 };
    for (int i = 0; i < 8; i++) {
      int x = u + dx[i], y = v + dy[i];
      if (x >= 1 && x <= n && y >= 1 && y <= n) {
        s.insert({ x, y });
      }
    }
    s.insert({ u, v });
    };

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    zuha(u, v);
  }
  cout << n * n - s.size() << '\n';
  return 0;
}
