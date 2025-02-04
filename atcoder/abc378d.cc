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
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> grid(n);
  for (auto& s : grid) cin >> s;
  auto count = [&](int x, int y) -> int {
    vector<vector<bool>> vis(n, vector<bool>(m));
    auto dfs = [&](auto&& self, int x, int y, int k) -> int {
      if (k == 0) return 1;
      const int dx[] = { 0, 0, 1, -1 };
      const int dy[] = { 1, -1, 0, 0 };
      vis[x][y] = true;
      int res = 0;
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] || grid[nx][ny] == '#') continue;
        res += self(self, nx, ny, k - 1);
      }
      vis[x][y] = false;
      return res;
      };
    return dfs(dfs, x, y, k);
    };
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (grid[i][j] == '.')
        ans += count(i, j);
  cout << ans << '\n';
  return 0;
}
