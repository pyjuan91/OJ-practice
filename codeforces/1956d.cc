#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n + 2), pref(n + 2);
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1));
  vector<vector<int>> split(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dp[i][i] = max(dp[i][i], a[i]);
    pref[i] = a[i] + pref[i - 1];
  }
  for (int len = 2; len <= n; len++) {
    for (int i = 1; i + len - 1 <= n; i++) {
      int j = i + len - 1;
      dp[i][j] = max(dp[i][j], pref[j] - pref[i - 1]);
      dp[i][j] = max(dp[i][j], len * len);
      for (int k = i; k < j; k++) {
        if (dp[i][j] < dp[i][k] + dp[k + 1][j]) {
          dp[i][j] = dp[i][k] + dp[k + 1][j];
          split[i][j] = k;
        }
      }
    }
  }

  vector<pair<int, int>> res;

  auto get_mex = [&](int l, int r) -> int {
    vector<int> cnt(n + 1);
    for (int i = l; i <= r; i++) {
      if (a[i] <= n) cnt[a[i]]++;
    }
    for (int i = 0; i <= n; i++) {
      if (cnt[i] == 0) {
        return i;
      }
    }
    return n + 1;
  };

  auto change_section_to_mex = [&](int l, int r) -> void {
    int mex = get_mex(l, r);
    res.push_back({l, r});
    fill(a.begin() + l, a.begin() + r + 1, mex);
  };

  auto change_zeros_section_to_len = [&](auto&& self, int l, int r) -> void {
    if (l > r) return;
    if (r == l) {
      while (a[l] != 1) change_section_to_mex(l, r);
      return;
    }
    self(self, l, r - 1);
    change_section_to_mex(l, r);
    change_section_to_mex(l, r - 1);
    self(self, l, r - 1);
  };

  auto chaewon = [&](auto&& chae, int l, int r) -> void {
    if (split[l][r] == 0) {
      if (pref[r] - pref[l - 1] < (r - l + 1) * (r - l + 1)) {
        while (accumulate(a.begin() + l, a.begin() + r + 1, 0LL) != 0LL) {
          change_section_to_mex(l, r);
        }
        change_zeros_section_to_len(change_zeros_section_to_len, l, r - 1);
        change_section_to_mex(l, r);
      }
      return;
    }
    chae(chae, l, split[l][r]), chae(chae, split[l][r] + 1, r);
  };

  chaewon(chaewon, 1, n);
  cout << dp[1][n] << ' ' << res.size() << '\n';
  for (auto [l, r] : res) {
    cout << l << ' ' << r << '\n';
  }
  return 0;
}
