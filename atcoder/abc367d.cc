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
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  vector<int> pref(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    pref[i] = a[i % n];
    if (i) pref[i] += pref[i - 1];
  }
  // debug(pref);
  int cur_mod = 0, res = 0;
  map<int, int> cnt;
  for (int i = 0; i < n - 1; i++) cnt[pref[i] % m]++;
  for (int i = 0; i < n; i++) {
    res += cnt[cur_mod];
    cnt[pref[i + n - 1] % m]++;
    cnt[pref[i] % m]--;
    cur_mod = (cur_mod + a[i]) % m;
  }
  cout << res << '\n';
  return 0;
}
