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
  vector<pair<int, int>> side_dishes;
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    side_dishes.push_back(make_pair(u, v));
  }
  int res = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    int v_sum = 0, u_sum = 0;
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        v_sum += side_dishes[i].first;
        u_sum += side_dishes[i].second;
      }
    }
    if (u_sum <= m) res = max(res, v_sum);
  }
  cout << res << "\n";
  return 0;
}
