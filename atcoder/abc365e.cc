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
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  int res = 0;
  for (int j = 0;j < 32;j++) {
    int cnt = 0, cnt_even = 1, cnt_odd = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] & (1LL << j)) cnt++;
      if (cnt & 1) {
        res += (1LL << j) * cnt_even;
        // cnt_even = 0;
        cnt_odd++;
      } else {
        res += (1LL << j) * cnt_odd;
        // cnt_odd = 0;
        cnt_even++;
      }
      debug(j, i, cnt, cnt_even, cnt_odd, res);
    }
  }
  cout << res - accumulate(a.begin(), a.end(), 0LL) << '\n';
  return 0;
}
