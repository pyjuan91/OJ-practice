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
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int nim = 0;
    while (n--) {
      int x;
      cin >> x;
      nim = nim xor x;
    }
    cout << (nim == 0 ? "No" : "Yes") << "\n";
  }
  return 0;
}
