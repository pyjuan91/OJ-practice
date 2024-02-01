#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  while (cin >> n >> m && n) {
    vector<string> g(n);
    for (auto& s : g) cin >> s;

    vector<vector<bool>> vist(n, vector<bool>(m, false));
    const int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    const int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int res = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!vist[i][j] && g[i][j] == '@') {
          res++;
          queue<int> qx, qy;
          qx.push(i), qy.push(j);
          vist[i][j] = true;
          while (!qx.empty()) {
            auto cur_x = qx.front(), cur_y = qy.front();
            qx.pop(), qy.pop();
            auto is_valid = [&](int x, int y) {
              return (x >= 0) && (x < n) && (y >= 0) && (y < m);
            };
            for (int k = 0; k < 8; k++) {
              auto neo_x = cur_x + dx[k];
              auto neo_y = cur_y + dy[k];
              if (is_valid(neo_x, neo_y) && !vist[neo_x][neo_y] &&
                  g[neo_x][neo_y] == '@') {
                vist[neo_x][neo_y] = true;
                qx.push(neo_x), qy.push(neo_y);
              }
            }
          }
        }
      }
    }
    cout << res << "\n";
  }
  return 0;
}
