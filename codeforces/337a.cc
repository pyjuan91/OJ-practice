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
  int m, n;
  cin >> m >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  sort(a.begin(), a.end());
  int res = INT64_MAX;
  for (int i = m - 1; i < n; i++) {
    res = min(res, a[i] - a[i - m + 1]);
  }
  cout << res << '\n';
  return 0;
}
