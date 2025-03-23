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
  if (n % 2) {
    for (int i = 0; i < n; i++) {
      if (i == n / 2) cout << "=";
      else cout << "-";
    }
  }
  else {
    for (int i = 0; i < n; i++) {
      if (i == n / 2 - 1 or i == n / 2) cout << "=";
      else cout << "-";
    }
  }
  return 0;
}
