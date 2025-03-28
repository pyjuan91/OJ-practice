#include <bits/stdc++.h>
#include <atcoder/modint>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
#define double long double
using namespace std;
using mint = atcoder::modint998244353;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n, m, d;
  cin >> t;
  while (t--) {
    cin >> n >> m >> d;
    vector<string> g(n);
    for (auto& i : g) cin >> i;
    vector dp(n, vector(m, vector<mint>(2, 0)));
    for (int i = 0; i < m; i++) {
      if (g[n - 1][i] == 'X') dp[n - 1][i][0] = 1;
      if (i) dp[n - 1][i][0] += dp[n - 1][i - 1][0];
    }
    for (int i = 0; i < m; i++) {
      int left = max(0LL, i - d), right = min(m - 1, i + d);
      if (g[n - 1][i] == 'X') {
        dp[n - 1][i][1] = (i - 1 >= 0 ? dp[n - 1][i - 1][0] : 0)
          - (left - 1 >= 0 ? dp[n - 1][left - 1][0] : 0)
          + dp[n - 1][right][0]
          - dp[n - 1][i][0];
      }
      if (i) {
        dp[n - 1][i][1] += dp[n - 1][i - 1][1];
      }
    }
    double shrink_dd = sqrt(static_cast<double>(d * d - 1));
    int shrink_d = static_cast<int>(shrink_dd);
    for (int i = n - 2; i >= 0; i--) {
      for (int j = 0; j < m; j++) {
        int left = max(0LL, j - shrink_d), right = min(m - 1, j + shrink_d);
        if (g[i][j] == 'X') {
          dp[i][j][0] = dp[i + 1][right][0] - (left - 1 >= 0 ? dp[i + 1][left - 1][0] : 0)
            + dp[i + 1][right][1] - (left - 1 >= 0 ? dp[i + 1][left - 1][1] : 0);
        }
        if (j) {
          dp[i][j][0] += dp[i][j - 1][0];
        }
      }
      for (int j = 0; j < m; j++) {
        int left = max(0LL, j - d), right = min(m - 1, j + d);
        if (g[i][j] == 'X') {
          dp[i][j][1] = (j - 1 >= 0 ? dp[i][j - 1][0] : 0)
            - (left - 1 >= 0 ? dp[i][left - 1][0] : 0)
            + dp[i][right][0]
            - dp[i][j][0];
        }
        if (j) {
          dp[i][j][1] += dp[i][j - 1][1];
        }
      }
    }
    mint res = dp[0][m - 1][0] + dp[0][m - 1][1];
    cout << res.val() << "\n";
  }
  return 0;
}
