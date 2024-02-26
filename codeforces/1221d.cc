#include <bits/stdc++.h>
#define int long long
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int zuha(vi& h, vi& c, vvi& dp, int n, int id, int extra) {
  if (id == n) return 0;
  if (dp[id][extra] != -1) return dp[id][extra];
  int& res = dp[id][extra] = INT64_MAX;
  for (int i = 0; i < 3; i++) {
    if (id == 0 || h[id] + i != h[id - 1] + extra) {
      res = min(res, c[id] * i + zuha(h, c, dp, n, id + 1, i));
    }
  }
  return res;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> h(n), c(n);
    for (int i = 0; i < n; i++) cin >> h[i] >> c[i];
    vector<vector<int>> dp(n, vector<int>(3, -1));
    cout << zuha(h, c, dp, n, 0, 0) << '\n';
  }
  return 0;
}
