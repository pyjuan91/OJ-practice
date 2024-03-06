#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  ::cin.tie(nullptr)->sync_with_stdio(false);
  const int kMod = 998244353;

  auto fast_power = [&](int base, int expo) {
    int res = 1;
    while (expo) {
      if (expo & 1) res = res * base % kMod;
      expo >>= 1;
      base = base * base % kMod;
    }
    return res;
  };

  auto mod_reverse = [&](int x) { return fast_power(x, kMod - 2); };

  auto mod_div = [&](int a, int b) { return a * mod_reverse(b) % kMod; };

  int n, m;
  ::cin >> n >> m;
  vector<int> a(n);
  for (auto& x : a) ::cin >> x;
  vector<int> dp(m + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < n; j++) {
      if (i - a[j] >= 0 && dp[i - a[j]] > 0) {
        dp[i] += dp[i - a[j]];
        dp[i] %= kMod;
      }
    }
    dp[i] *= mod_div(1, n);
    dp[i] %= kMod;
  }
  int res = 0;
  for (int i = max(m - a[0] + 1, 0ll); i <= m; i++) {
    res += dp[i] * mod_div(1, n);
    res %= kMod;
  }
  cout << res << "\n";
  return 0;
}
