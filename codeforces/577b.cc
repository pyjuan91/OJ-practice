#include <bits/stdc++.h>
using namespace std;

bool kazuha(int m, vector<int>& cnt) {
  vector<vector<bool>> dp(1000, vector<bool>(1000, false));
  if (cnt[0]) return true;

  for (int i = 1; i < m; i++) {
    for (int j = 1; j <= cnt[i]; j++) {
      dp[i][j * i % m] = true;
    }
    if (i > 1) {
      for (int j = 1; j < m; j++) {
        if (dp[i - 1][j]) {
          for (int k = 0; k <= cnt[i]; k++) {
            dp[i][(j + i * k) % m] = true;
          }
        }
      }
    }
    if (dp[i][0]) return true;
  }

  return false;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, x;
  vector<int> cnt(1000, 0);
  cin >> n >> m;
  while (n--) cin >> x, cnt[x % m]++;
  cout << (kazuha(m, cnt) ? "YES\n" : "NO\n");
  return 0;
}
