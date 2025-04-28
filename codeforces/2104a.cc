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
  int t, a, b, c;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    int x = a + b + c;
    if (x % 3 != 0) {
      cout << "NO\n";
      continue;
    }
    x /= 3;
    if (a <= x and b <= x and c >= x) {
      cout << "YES\n";
      continue;
    }
    cout << "NO\n";
  }
  return 0;
}
