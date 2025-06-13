#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

void patty(int n, int k) {
  for (int i = 0; i < n; i++) {
    int res = 1;
    for (int j = 0; j < 20; j++) {
      if ((((n - 1) >> j) & 1) == 0 and ((i >> j) & 1) == 1) res = 0;
    }
    if (res)
      cout << k << " ";
    else
      cout << 0 << " ";
  }
  cout << "\n";
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    patty(n, k);
  }
  return 0;
}
