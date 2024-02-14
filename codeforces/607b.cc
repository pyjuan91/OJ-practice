#include <bits/stdc++.h>
using namespace std;

int n, dp[505][505], a[505];

int kazuha(int l, int r) {
  if (l > r) return 0;
  if (l == r) return 1;
  if (dp[l][r] != -1) return dp[l][r];
  int res = kazuha(l, r - 1) + 1;
  for (int nice_l = l; nice_l < r; nice_l++) {
    if (a[nice_l] == a[r]) {
      res = min(res, kazuha(l, nice_l - 1) + kazuha(nice_l + 1, r - 1) +
                         (nice_l == r - 1 ? 1 : 0));
    }
  }
  return dp[l][r] = res;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  memset(dp, -1, sizeof(dp));
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cout << kazuha(1, n) << '\n';
  return 0;
}
