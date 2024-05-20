#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, x, y;
  cin >> t;
  while (t--) {
    cin >> x >> y;
    int quota = 0, res = 0;
    if (y % 2 == 0) {
      res = y / 2;
      quota = 7 * res;
      x = max(0LL, x - quota);
      res += x / 15 + (x % 15 != 0);
    } else {
      res = y / 2 + 1;
      quota = 7 * (res - 1) + 11;
      x = max(0LL, x - quota);
      res += x / 15 + (x % 15 != 0);
    }
    cout << res << '\n';
  }
  return 0;
}
