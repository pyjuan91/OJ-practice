#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMax = 5005, kMod = 998244353;
int n, a[kMax], pref[kMax], pre_reachable_sum[kMax][kMax];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i];

  pre_reachable_sum[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int su = 0; su <= pref[i]; su++) {
      pre_reachable_sum[i][su] = pre_reachable_sum[i - 1][su];
    }
    for (int su = 5004; su >= a[i]; su--) {
      pre_reachable_sum[i][su] += pre_reachable_sum[i - 1][su - a[i]];
      pre_reachable_sum[i][su] %= kMod;
    }
  }

  int res = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= pref[i - 1]; j++) {
      if (j > a[i]) {
        res += pre_reachable_sum[i - 1][j] *
               (a[i] + ((j - a[i]) / 2 + (j - a[i]) % 2)) % kMod;
      } else {
        res += pre_reachable_sum[i - 1][j] * a[i] % kMod;
      }
    }
  }

  cout << res % kMod << '\n';
  return 0;
}