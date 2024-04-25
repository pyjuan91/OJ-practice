#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMax = 2e6 + 5, kMod = 1e9 + 7;
int dp[kMax], t, n;

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  dp[1] = dp[2] = 0;
  for (int i = 3; i < kMax; i++) {
    dp[i] = dp[i - 1] + 2 * dp[i - 2] + (i % 3 == 0);
    dp[i] %= kMod;
  }
  cin >> t;
  while (t--) {
    cin >> n;
    cout << dp[n] * 4 % kMod << "\n";
  }
  return 0;
}
