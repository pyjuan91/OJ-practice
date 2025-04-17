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
  int t, n, q;
  cin >> t;
  while (t--) {
    cin >> n >> q;
    vector a(n + 1, vector(n + 1, 0ll));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> a[i][j];
      }
    }

    vector prefix(n + 1, vector(n + 1, 0ll));
    vector prefix2(n + 1, vector(n + 1, 0ll));
    vector prefix3(n + 1, vector(n + 1, 0ll));

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + a[i][j];
        prefix2[i][j] = prefix2[i - 1][j] + prefix2[i][j - 1] - prefix2[i - 1][j - 1] + a[i][j] * i;
        prefix3[i][j] = prefix3[i - 1][j] + prefix3[i][j - 1] - prefix3[i - 1][j - 1] + a[i][j] * j;
      }
    }

    auto query = [](int x1, int y1, int x2, int y2, const auto& arr) {
      return arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1];
      };

    while (q--) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      int ans = (-x1 * (y2 - y1 + 1) - y1 + 1) * query(x1, y1, x2, y2, prefix) +
        (y2 - y1 + 1) * query(x1, y1, x2, y2, prefix2) +
        query(x1, y1, x2, y2, prefix3);
      cout << ans << " ";
    }
    cout << "\n";
  }
  return 0;
}
