#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n, m, k;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    vector<int> a(n), b(m), c(k);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    for (auto &i : c) cin >> i;
    multiset<pair<int, int>> s;
    for (int i = 1; i < n; i++) s.insert({a[i] - a[i - 1], i});
    auto [max_sec, max_idx] = *s.rbegin();
    s.erase(*s.rbegin());
    sort(c.begin(), c.end());
    // for (auto i : c) cout << i << ' ';
    // cout << '\n';
    // for (auto i : s) cout << i.first << ' ' << i.second << '\n';
    // cout << max_sec << ' ' << max_idx << '\n';
    // try to find b[i] + c[j] between a[max_idx - 1] and a[max_idx]
    int ideal = (a[max_idx] + a[max_idx - 1]) / 2;
    int res = max_sec;
    auto get_sec = [&](int x) {
      return max(llabs(a[max_idx] - x), llabs(a[max_idx - 1] - x));
    };
    for (int i = 0; i < m; i++) {
      auto it = lower_bound(c.begin(), c.end(), ideal - b[i]);
      if (it != c.end() && *it + b[i] <= a[max_idx] &&
          *it + b[i] >= a[max_idx - 1]) {
        if (get_sec(*it + b[i]) < res) res = get_sec(*it + b[i]);
      }
      if (it != c.begin()) {
        it--;
        if (*it + b[i] <= a[max_idx] && *it + b[i] >= a[max_idx - 1]) {
          if (get_sec(*it + b[i]) < res) res = get_sec(*it + b[i]);
        }
      }
    }
    s.insert({res, max_idx});
    cout << s.rbegin()->first << '\n';
  }
  return 0;
}
