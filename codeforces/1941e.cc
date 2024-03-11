#include <bits/stdc++.h>
#define int long long
using namespace std;

int chaewon(int n, int m, int k, int d, vector<vector<int>>& a) {
  vector<vector<int>> dp(n, vector<int>(m));
  for (int i = 0; i < n; i++) dp[i][0] = 1;
  for (int i = 0; i < n; i++) {
    set<pair<int, int>> s;
    s.insert({1, 0});
    for (int j = 1; j < m; j++) {
      while (!s.empty() && s.begin()->second < j - d - 1) s.erase(s.begin());
      dp[i][j] = s.begin()->first + a[i][j] + 1;
      s.insert({dp[i][j], j});
    }
  }
  int res = INT64_MAX, sum = 0;
  for (int i = 0; i < k - 1; i++) sum += dp[i][m - 1];
  for (int i = k - 1; i < n; i++) {
    sum += dp[i][m - 1];
    res = min(res, sum);
    sum -= dp[i - k + 1][m - 1];
  }
  return res;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n, m, k, d;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k >> d;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    cout << chaewon(n, m, k, d, a) << '\n';
  }
  return 0;
}
