#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, m, d, a, b;
  cin >> n >> m >> d;
  vector<vector<int>> g(n);
  vector<bool> evil(n, false);
  int evil_a, evil_b;
  while (m--) cin >> a, evil[--a] = true, evil_a = evil_b = a;
  vector<int> dist_a(n, 0), dist_b(n, 0);

  for (int i = 1; i < n; i++)
    cin >> a >> b, g[--a].push_back(--b), g[b].push_back(a);

  function<void(int, int, int&, vector<int>&)> zuha =
      [&](int u, int p, int& cur_e, vector<int>& cur_dist) {
        if (evil[u] && cur_dist[u] > cur_dist[cur_e]) cur_e = u;
        for (auto& v : g[u]) {
          if (v != p) {
            cur_dist[v] = cur_dist[u] + 1;
            zuha(v, u, cur_e, cur_dist);
          }
        }
      };
  zuha(evil_a, -1, evil_a, dist_a);
  dist_a.assign(n, 0);
  zuha(evil_a, -1, evil_b, dist_a);
  zuha(evil_b, -1, evil_a, dist_b);
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (dist_a[i] <= d && dist_b[i] <= d) res++;
  }
  cout << res << '\n';
  return 0;
}
