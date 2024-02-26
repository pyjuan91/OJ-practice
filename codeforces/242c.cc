#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  const int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
  const int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};

  int x0, y0, x1, y1, n, r, a, b;
  cin >> x0 >> y0 >> x1 >> y1 >> n;
  set<pair<int, int>> valid_set;
  while (n--) {
    cin >> r >> a >> b;
    for (int i = a; i <= b; i++) {
      valid_set.insert({r, i});
    }
  }

  queue<pair<int, int>> q;
  queue<int> steps;
  q.push({x0, y0}), steps.push(0), valid_set.erase({x0, y0});
  while (!q.empty()) {
    auto [x, y] = q.front();
    int step = steps.front();
    q.pop(), steps.pop();
    if (x == x1 && y == y1) {
      cout << step << '\n';
      return 0;
    }
    for (int i = 0; i < 8; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx >= 1 && nx <= 1e9 && ny >= 1 && ny <= 1e9 &&
          valid_set.count({nx, ny})) {
        q.push({nx, ny});
        steps.push(step + 1);
        valid_set.erase({nx, ny});
      }
    }
  }
  cout << -1 << '\n';

  return 0;
}
