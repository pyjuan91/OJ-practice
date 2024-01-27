#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;
  for (auto &x : c) cin >> x;
  int res = 0;
  for (int b_cnt = 0; b_cnt <= 1000000; b_cnt++) {
    vector<int> remaining = a;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      remaining[i] -= b_cnt * b[i];
      if (remaining[i] < 0) {
        ok = false;
        break;
      }
    }
    if (!ok) break;
    int c_cnt = INT32_MAX;
    for (int i = 0; i < n; i++) {
      if (c[i] == 0) continue;
      c_cnt = min(c_cnt, remaining[i] / c[i]);
    }
    res = max(res, b_cnt + c_cnt);
  }
  cout << res << '\n';
  return 0;
}
