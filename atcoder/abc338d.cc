#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (auto &x : a) cin >> x, x--;

  vector<int> pref_time_chages(n + 1);
  int total_time = 0;
  for (int i = 1; i < m; i++) {
    int u = a[i - 1], v = a[i];
    if (u > v) swap(u, v);
    int section = v - u;
    total_time += section;
    pref_time_chages[u] += n - 2 * section;
    pref_time_chages[v] -= n - 2 * section;
  }

  int res = INT64_MAX;
  for (int i = 0; i < n; i++) {
    if (i) pref_time_chages[i] += pref_time_chages[i - 1];
    res = min(res, total_time + pref_time_chages[i]);
  }
  cout << res << '\n';
  return 0;
}
