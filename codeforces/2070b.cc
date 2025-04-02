#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

int haerin(string& s, int n, int x, int k) {
  if (x < 0) {
    x = llabs(x);
    for (auto& c : s) {
      if (c == 'L') {
        c = 'R';
      }
      else if (c == 'R') {
        c = 'L';
      }
    }
  }
  if (x > n) {
    return 0;
  }


  vector<int> prefix(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'L') prefix[i] = 1;
    else if (s[i] == 'R') prefix[i] = -1;
    prefix[i] += prefix[i - 1];
  }

  debug(prefix);
  int steps_to_zero = 0;
  for (int i = 1; i <= n; i++) {
    if (prefix[i] == x) {
      steps_to_zero = i;
      break;
    }
  }
  if (steps_to_zero == 0) {
    return 0;
  }
  k -= steps_to_zero;
  debug(steps_to_zero, k);
  if (k < 0) {
    return 0;
  }
  // // everyone is at zero
  int steps_return_zero = 0;
  for (int i = 1; i <= n; i++) {
    if (prefix[i] == 0) {
      steps_return_zero = i;
      break;
    }
  }
  if (steps_return_zero == 0) {
    return 1;
  }
  debug(steps_return_zero);
  return k / steps_return_zero + 1;
  return 0;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n, x, k;
  string s;
  cin >> t;
  while (t--) {
    cin >> n >> x >> k >> s;
    s = " " + s;
    cout << haerin(s, n, x, k) << '\n';
  }
  return 0;
}
