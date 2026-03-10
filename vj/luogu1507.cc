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
  int n, m, t;
  cin >> n >> m >> t;
  vector dp(n + 1, vector(m + 1, 0LL));
  while (t--) {
    int i, j, k;
    cin >> i >> j >> k;
    for (int ii = n; ii >= i; ii--) {
      for (int jj = m; jj >= j; jj--) {
        dp[ii][jj] = max(dp[ii][jj], dp[ii - i][jj - j] + k);
      }
    }
  }
  cout << std::ranges::max(dp | std::views::join) << "\n";
  return 0;
}
