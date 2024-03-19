#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    vector<int> a(n + 2), b(n + 2);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    int sum = 0, res = INT64_MAX;
    for (int i = n; i >= 1; i--) {
      if (i <= m) {
        res = min(res, sum + a[i]);
      }
      sum += min(b[i], a[i]);
    }
    cout << res << "\n";
  }
  return 0;
}
