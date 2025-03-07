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
  int n, m;
  cin >> n >> m;
  vector<string> g(n);
  for (auto& s : g) cin >> s;
  vector dp(n, vector(m, vector<int>(4, INT64_MAX)));
  const int dx[] = { 0, 0, 1, -1 };
  const int dy[] = { 1, -1, 0, 0 };
  int sx, sy, ex, ey;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == 'S') sx = i, sy = j;
      if (g[i][j] == 'G') ex = i, ey = j;
    }
  }
  debug(sx, sy, ex, ey);
  auto valid = [&](int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && g[x][y] != '#';
    };
  // bfs
  for (int i = 0; i < 4; i++) {
    dp[sx][sy][i] = 0;
    queue<tuple<int, int, int>> q;
    q.emplace(sx, sy, i);
    while (!q.empty()) {
      auto [x, y, d] = q.front();
      debug(x, y, d);
      q.pop();
      if (d < 2) {
        for (int j = 2; j < 4; j++) {
          int nx = x + dx[j];
          int ny = y + dy[j];
          if (valid(nx, ny) && dp[nx][ny][j] == INT64_MAX) {
            dp[nx][ny][j] = dp[x][y][d] + 1;
            q.emplace(nx, ny, j);
          }
        }
      }
      else {
        for (int j = 0; j < 2; j++) {
          int nx = x + dx[j];
          int ny = y + dy[j];
          if (valid(nx, ny) && dp[nx][ny][j] == INT64_MAX) {
            dp[nx][ny][j] = dp[x][y][d] + 1;
            q.emplace(nx, ny, j);
          }
        }
      }
    }
  }
  int res = INT64_MAX;
  for (int i = 0; i < 4; i++) {
    if (dp[ex][ey][i] != INT64_MAX) res = min(res, dp[ex][ey][i]);
  }
  debug(dp);
  if (res == INT64_MAX) cout << -1 << '\n';
  else cout << res << '\n';
  return 0;
}
