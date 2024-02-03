#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  const int dx[] = {-1, 0, 1, 0};
  const int dy[] = {0, 1, 0, -1};

  cin >> n;
  vector<string> a(n);
  for (auto& x : a) cin >> x;
  auto dist = vector<vector<vector<vector<int>>>>(
      n, vector<vector<vector<int>>>(
             n, vector<vector<int>>(n, vector<int>(n, -1))));
  auto valid = [&](int x, int y) { return x >= 0 && x < n && y >= 0 && y < n; };
  queue<pair<int, int>> q1, q2;
  queue<int> d;
  pair<int, int> p1 = {-1, -1}, p2 = {-1, -1};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 'P') {
        if (p1.first == -1)
          p1 = {i, j};
        else
          p2 = {i, j};
      }
    }
  }
  q1.push(p1);
  q2.push(p2);
  d.push(0);
  dist[p1.first][p1.second][p2.first][p2.second] = 0;
  while (!q1.empty()) {
    p1 = q1.front(), p2 = q2.front();
    int cur_d = d.front();
    q1.pop(), q2.pop(), d.pop();
    if (p1 == p2) {
      cout << cur_d << "\n";
      return 0;
    }
    for (int i = 0; i < 4; i++) {
      pair<int, int> np1 = {p1.first + dx[i], p1.second + dy[i]};
      pair<int, int> np2 = {p2.first + dx[i], p2.second + dy[i]};
      if (!valid(np1.first, np1.second) || a[np1.first][np1.second] == '#')
        np1 = p1;
      if (!valid(np2.first, np2.second) || a[np2.first][np2.second] == '#')
        np2 = p2;
      if (dist[np1.first][np1.second][np2.first][np2.second] == -1) {
        dist[np1.first][np1.second][np2.first][np2.second] = cur_d + 1;
        q1.push(np1);
        q2.push(np2);
        d.push(cur_d + 1);
      }
    }
  }
  cout << "-1\n";
  return 0;
}
