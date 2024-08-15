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
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n + 1), pref(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      pref[i] = pref[i - 1] + a[i];
    }
    string seq;
    cin >> seq, seq = " " + seq;
    int ans = 0, l = 1, r = n;
    while (l < r) {
      while (l < r and seq[l] == 'R') l++;
      while (l < r and seq[r] == 'L') r--;
      if (l < r) {
        ans += pref[r] - pref[l - 1];
        l++, r--;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
