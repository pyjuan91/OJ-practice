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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto& x : a) cin >> x, x %= k;
  sort(a.begin(), a.end());
  int res = 0;
  for (int i = 1; i < n; i++) {
    res = max(res, a[i] - a[i - 1]);
  }
  res = max(res, a[0] + k - a[n - 1]);
  cout << k - res << "\n";
  return 0;
}
