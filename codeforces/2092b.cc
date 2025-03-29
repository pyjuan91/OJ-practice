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
  string a, b;
  cin >> t;
  while (t--) {
    cin >> n >> a >> b;
    int comp1_ones = 0, comp2_ones = 0;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) comp1_ones += (a[i] == '1');
      else comp2_ones += (a[i] == '1');
    }
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0)comp2_ones += (b[i] == '1');
      else comp1_ones += (b[i] == '1');
    }
    int ac1 = n / 2, ac2 = n - n / 2;
    cout << (comp1_ones <= ac1 and comp2_ones <= ac2 ? "YES" : "NO") << '\n';
  }
  return 0;
}
