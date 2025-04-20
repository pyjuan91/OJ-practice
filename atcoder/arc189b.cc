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
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  vector<int> odd, even;
  for (int i = 0; i + 1 < n; i++) {
    if (i % 2 == 0) even.push_back(a[i + 1] - a[i]);
    else odd.push_back(a[i + 1] - a[i]);
  }
  sort(odd.rbegin(), odd.rend());
  sort(even.rbegin(), even.rend());
  int res = 0, pos = a[0];
  bool even_turn = true;
  for (;;) {
    res += pos;
    if (even_turn) {
      if (even.empty()) break;
      pos += even.back();
      even.pop_back();
    }
    else {
      if (odd.empty()) break;
      pos += odd.back();
      odd.pop_back();
    }
    even_turn = !even_turn;
  }
  cout << res << "\n";
  return 0;
}
