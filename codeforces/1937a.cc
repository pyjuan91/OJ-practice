#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int res = 0;
    for (int i = 31; i >= 0; i--) {
      if (n & (1 << i)) {
        res = 1 << i;
        break;
      }
    }
    cout << res << '\n';
  }
  return 0;
}
