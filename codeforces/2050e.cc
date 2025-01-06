#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  string a, b, c;

  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    size_t a_len = a.size(), b_len = b.size(), c_len = c.size();
    vector<vector<int>> dp(c_len + 1, vector<int>(a_len + 1, 5e5));

    auto haerin = [&](auto&& self, int tot_idx, int a_idx) -> int {
      if (dp[tot_idx][a_idx] != 5e5) return dp[tot_idx][a_idx];
      if (tot_idx == c_len) return 0;
      // run out of a
      if (a_idx == a_len) {
        int b_idx = tot_idx - a_idx;
        int b_diff = 0;
        for (int i = b_idx; i < b_len; i++) {
          b_diff += b[i] != c[tot_idx + i - b_idx];
        }
        return dp[tot_idx][a_idx] = b_diff;
      }

      int fill_a = (c[tot_idx] == a[a_idx] ? 0 : 1) + self(self, tot_idx + 1, a_idx + 1);
      int b_idx = tot_idx - a_idx;
      if (b_idx >= b_len) return dp[tot_idx][a_idx] = fill_a;
      int fill_b = (c[tot_idx] == b[b_idx] ? 0 : 1) + self(self, tot_idx + 1, a_idx);
      return dp[tot_idx][a_idx] = min(fill_a, fill_b);
      };

    cout << haerin(haerin, 0, 0) << '\n';
  }

  return 0;
}
