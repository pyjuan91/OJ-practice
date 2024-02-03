#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, k, dir = 0, x = 0, y = 0;
  const int dx[] = {-1, 0, 1, 0};
  const int dy[] = {0, 1, 0, -1};
  cin >> n >> m >> k;
  vector<vector<char>> g(n, vector<char>(m, '.'));
  auto paint_black = [&](int& x, int& y, int& dir) {
    g[x][y] = '#';
    dir = (dir + 1) % 4;
    x = (x + dx[dir] + n) % n;
    y = (y + dy[dir] + m) % m;
  };
  auto paint_white = [&](int& x, int& y, int& dir) {
    g[x][y] = '.';
    dir = (dir + 3) % 4;
    x = (x + dx[dir] + n) % n;
    y = (y + dy[dir] + m) % m;
  };
  while (k--) {
    if (g[x][y] == '.')
      paint_black(x, y, dir);
    else
      paint_white(x, y, dir);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << g[i][j];
    cout << "\n";
  }
  return 0;
}
