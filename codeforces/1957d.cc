#include <bits/stdc++.h>
using namespace std;

const int kMax = 1e5 + 5;
int a[kMax], pref[kMax][32][2], suff[kMax][32][2];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i <= n + 1; i++) {
      for (int j = 0; j < 32; j++) {
        pref[i][j][0] = pref[i][j][1] = 0;
        suff[i][j][0] = suff[i][j][1] = 0;
      }
    }
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 32; j++) {
        int t = ((a[i] >> j) & 1);
        for (int k = 0; k < 2; k++) {
          pref[i][j][k] = (t == k) + pref[i - 1][j][k ^ t];
        }
      }
    }

    for (int i = n; i >= 1; i--) {
      for (int j = 0; j < 32; j++) {
        int t = ((a[i] >> j) & 1);
        for (int k = 0; k < 2; k++) {
          suff[i][j][k] = (t == k) + suff[i + 1][j][k ^ t];
        }
      }
    }

    int64_t ans = 0;
    for (int i = 1; i <= n; i++) {
      int msb = 31 - __builtin_clz(a[i]);
      ans += 1LL * (1 + pref[i - 1][msb][0]) * suff[i + 1][msb][1] +
             1LL * pref[i - 1][msb][1] * (1 + suff[i + 1][msb][0]);
    }
    cout << ans << '\n';
  }
  return 0;
}
