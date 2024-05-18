#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto& [x, y] : a) cin >> x >> y;

  vector<int> dp(1 << n, -1);
  auto kazuha = [&](auto&& zuha, int mask) -> int {
    if (dp[mask] != -1) return dp[mask];
    int& res = dp[mask] = 0;
    if (__builtin_popcount(mask) <= 1) return res = 0;
    for (int i = 0; i < n; i++) {
      if (mask >> i & 1) {
        for (int j = i + 1; j < n; j++) {
          if (mask >> j & 1) {
            if (a[i].first == a[j].first || a[i].second == a[j].second) {
              if (zuha(zuha, mask ^ (1 << i) ^ (1 << j)) == 0) return res = 1;
            }
          }
        }
      }
    }
    return res;
  };
  cout << (kazuha(kazuha, (1 << n) - 1) ? "Takahashi" : "Aoki") << '\n';
  return 0;
}
