#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    bool ok = true;
    for (int i = 0; i < n - 2; i++) {
      if (a[i] == 0)
        continue;
      else if (a[i] < 0)
        ok = false;
      else {
        a[i + 1] -= 2 * a[i];
        a[i + 2] -= a[i];
        a[i] = -a[i];
      }
      // for (auto x : a) cout << x << ' ';
      // cout << '\n';
    }
    cout << (ok && a[n - 2] == 0 && a[n - 1] == 0 ? "YES" : "NO") << '\n';
  }
  return 0;
}
