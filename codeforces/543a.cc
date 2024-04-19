#include <bits/stdc++.h>
using namespace std;

const int kMax = 501;
int n, m, k, kMod;
int dp[kMax][kMax], a[kMax];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m >> k >> kMod;
  for (int i = 1; i <= n; i++) cin >> a[i];

  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int sel_cnt = 1; sel_cnt <= m; sel_cnt++) {
      for (int bug_cnt = a[i]; bug_cnt <= k; bug_cnt++) {
        dp[sel_cnt][bug_cnt] += dp[sel_cnt - 1][bug_cnt - a[i]];
        dp[sel_cnt][bug_cnt] %= kMod;
      }
    }
  }

  int res = 0;
  for (int i = 0; i <= k; i++) {
    res += dp[m][i];
    res %= kMod;
  }
  cout << res << '\n';

  return 0;
}
