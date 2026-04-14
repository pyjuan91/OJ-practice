#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, x;
  cin >> t >> x;
  int a, saved = 300;
  for (int i = 0; i <= t; i++) {
    cin >> a;
    if (llabs(a - saved) >= x) {
      cout << i << " " << a << "\n";
      saved = a;
    }
  }
  return 0;
}
