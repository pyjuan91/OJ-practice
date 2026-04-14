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
  vector<string> g(n);
  for (int i = 0; i < n; i++) {
    cin >> g[i];
  }

  // Find starting point and destination
  pair<int, int> start, end;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == 'S') start = make_pair(i, j);
      if (g[i][j] == 'G') end = make_pair(i, j);
    }
  }

  // {U, D, L, R}
  constexpr array<int, 4> id_to_dir = {'U', 'D', 'L', 'R'};
  constexpr array<int, 4> dx = {-1, 1, 0, 0};
  constexpr array<int, 4> dy = {0, 0, -1, 1};

  vector vis(n, vector(m, vector(4, false)));
  vector<char> route;
  auto is_out_of_bound = [&](int x, int y) -> bool {
    return x < 0 or x >= n or y < 0 or y >= m;
  };
  debug(start, end);
  auto dfs = [&](this auto& self, int x, int y, int dir) -> void {
    vis[x][y][dir] = true;
    debug(x, y, dir);
    if (x == end.first and y == end.second) {
      cout << "Yes\n";
      for (const auto& c : route) cout << c;
      cout << "\n";
      exit(0);
    }
    if (g[x][y] == 'S' or g[x][y] == '.') {
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (is_out_of_bound(nx, ny) or vis[nx][ny][i] or g[nx][ny] == '#')
          continue;
        route.push_back(id_to_dir[i]);
        self(nx, ny, i);
        route.pop_back();
      }
    } else if (g[x][y] == 'o') {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (not is_out_of_bound(nx, ny) and not vis[nx][ny][dir] and
          g[nx][ny] != '#') {
        route.push_back(id_to_dir[dir]);
        self(nx, ny, dir);
        route.pop_back();
      }
    } else if (g[x][y] == 'x') {
      for (int i = 0; i < 4; i++) {
        if (i == dir) continue;
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (is_out_of_bound(nx, ny) or vis[nx][ny][i] or g[nx][ny] == '#')
          continue;
        route.push_back(id_to_dir[i]);
        self(nx, ny, i);
        route.pop_back();
      }
    }
    // vis[x][y][dir] = false;
  };

  dfs(start.first, start.second, 0);
  cout << "No\n";
  return 0;
}
