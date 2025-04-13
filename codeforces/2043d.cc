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
  int t, l, r, G;
  cin >> t;
  while (t--) {
    cin >> l >> r >> G;
    int haerin = [&]() {
      l = l / G + (l % G != 0);
      r = r / G;
      for (int len = r - l; len >= 0; len--) {
        for (int left = l; left <= r - len; left++) {
          int right = left + len;
          if (gcd(left, right) == 1) {
            cout << G * left << " " << G * right << "\n";
            return 0;
          }
        }
      }
      cout << "-1 -1\n";
      return 0;
    }();
  }
  return 0;
}
