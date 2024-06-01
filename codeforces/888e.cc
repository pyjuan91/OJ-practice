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
  for (auto &i : a) cin >> i;
  set<int> s[2];
  int n1 = n / 2, n2 = n - n1;
  for (int mask = 0; mask < (1 << n1); mask++) {
    int sum = 0;
    for (int i = 0; i < n1; i++) {
      if (mask & (1 << i)) sum += a[i];
    }
    s[0].insert(sum % m);
  }
  for (int mask = 0; mask < (1 << n2); mask++) {
    int sum = 0;
    for (int i = 0; i < n2; i++) {
      if (mask & (1 << i)) sum += a[n1 + i];
    }
    s[1].insert(sum % m);
  }

  int res = 0;
  for (auto i : s[0]) {
    // case 1: i + j < m
    auto it1 = s[1].lower_bound(m - i);
    if (it1 != s[1].begin()) {
      it1--;
      res = max(res, (i + *it1) % m);
    }
    // case 2: 2*m > i + j >= m
    auto it2 = s[1].lower_bound(2 * m - i);
    if (it2 != s[1].begin()) {
      it2--;
      res = max(res, (i + *it2) % m);
    }
  }
  cout << res << '\n';
  return 0;
}
