#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  vector<int> coins = {1, 3, 6, 10, 15};
  vector<int> dp(1001, 1e9);
  dp[0] = 0;
  for (int i = 1; i <= 1000; i++) {
    for (int j = 0; j < 5; j++) {
      if (i - coins[j] >= 0) {
        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
      }
    }
  }

  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n <= 1000)
      cout << dp[n] << "\n";
    else {
      int cnt_15 = (n - 900) / 15;
      n -= cnt_15 * 15;
      cout << dp[n] + cnt_15 << "\n";
    }
  }
  return 0;
}
