#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    int left_zero = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] == 0) {
        left_zero = i;
        break;
      }
    }
    if (left_zero == -1) {
      cout << n << "\n";
      continue;
    }
    debug(left_zero);
    int zeros = count(a.begin(), a.end(), 0);
    set<int> s = { 0 };
    for (int i = left_zero + 1; i < n; i++) {
      if (a[i]) s.insert(a[i]);
      debug(s);
    }
    int mex = 0;
    while (s.count(mex)) {
      mex++;
    }
    debug(mex);
    bool ok = true;
    for (int i = left_zero - 1; i >= 0; i--) {
      if (a[i] < mex) {
        ok = false;
        break;
      }
      s.insert(a[i]);
      while (s.count(mex)) {
        mex++;
      }
    }
    if (ok) cout << n - zeros + 1 << "\n";
    else cout << n - zeros << "\n";
  }
  return 0;
}
