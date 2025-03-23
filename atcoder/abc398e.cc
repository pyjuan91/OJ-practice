#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<bool>> g(n + 1, vector<bool>(n + 1, false));
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u][v] = g[v][u] = true;
  }
  vector<int> group_idx(n + 1, -1);
  group_idx[1] = 0;
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v = 1; v <= n; v++) {
      if (g[u][v] and group_idx[v] == -1) {
        group_idx[v] = group_idx[u] ^ 1;
        q.push(v);
      }
    }
  }
  int cnt[2] = { 0 };
  for (int i = 1; i <= n; i++) cnt[group_idx[i]]++;
  int remaining = cnt[0] * cnt[1] - (n - 1);
  if (remaining & 1) {
    cout << "First" << endl;
    cout.flush();
  }
  else {
    cout << "Second" << endl;
    cout.flush();
    int oppo_u, oppo_v;
    cin >> oppo_u >> oppo_v;
    if (oppo_u == -1) return 0;
    g[oppo_u][oppo_v] = g[oppo_v][oppo_u] = true;
  }

  vector<pair<int, int>> quota;
  for (int i = 1;i < n;i++) {
    for (int j = i + 1;j <= n;j++) {
      if (group_idx[i] != group_idx[j] and !g[i][j]) {
        quota.push_back({ i, j });
      }
    }
  }

  for (;;) {
    while (!quota.empty() and g[quota.back().first][quota.back().second]) {
      quota.pop_back();
    }
    cout << quota.back().first << " " << quota.back().second << endl;
    cout.flush();
    g[quota.back().first][quota.back().second] = g[quota.back().second][quota.back().first] = true;
    quota.pop_back();

    int oppo_u, oppo_v;
    cin >> oppo_u >> oppo_v;
    if (oppo_u == -1) return 0;
    g[oppo_u][oppo_v] = g[oppo_v][oppo_u] = true;
  }
  return 0;
}
