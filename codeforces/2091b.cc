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
  int t, n, x;
  cin >> t;
  while (t--) {
    cin >> n >> x;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());
    int res = 0, prv_idx = n - 1, score = a[n - 1], idx = n - 1;
    while (idx >= 0) {
      if (score >= x) {
        res++;
        idx--;
        if (idx >= 0) {
          score = a[idx];
          prv_idx = idx;
        }
      }
      else {
        idx--;
        if (idx >= 0) {
          score = a[idx] * (prv_idx - idx + 1);
        }
      }
    }
    cout << res << "\n";
  }
  return 0;
}
