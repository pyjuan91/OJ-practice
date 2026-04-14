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
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  int res = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    double pos = 0.5;
    int num_passing_zero = 0;
    for (int j = 0; j < n; j++) {
      double neo_pos = pos;
      if (mask & (1 << j)) {
        neo_pos += a[j];
      } else {
        neo_pos -= a[j];
      }
      if (pos * neo_pos < 0) num_passing_zero++;
      pos = neo_pos;
    }
    res = max(res, num_passing_zero);
  }
  cout << res << "\n";
  return 0;
}
