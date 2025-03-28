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
    if (n % 2 == 0) cout << "-1\n";
    else {
      vector<int> a(n);
      for (int i = 1; i <= n; i++) {
        int idx = ((i - 1) + (i - 1)) % n;
        a[idx] = i;
      }
      for (auto& i : a) cout << i << " ";
      cout << "\n";
    }
  }
  return 0;
}
