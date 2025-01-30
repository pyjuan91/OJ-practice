#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
using namespace std;

class Solution {
public:
  int maximumAmount(vector<vector<int>>& coins) {
    int n = coins.size(), m = coins[0].size();
    static constexpr int kMin = -5e7 - 5;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, kMin)));

    auto get_max_profit = [&](auto&& self, int x, int y, int quota) -> int {
      if (x == n - 1 and y == m - 1) {
        if (quota > 0) return max(coins[x][y], 0);
        return coins[x][y];
      }

      int& res = dp[x][y][quota];
      if (res != kMin) return res;

      const int kDx[] = { 0, 1 }, kDy[] = { 1, 0 };
      if (quota > 0) {
        // Use neutralization
        int profit = 0;
        for (int i = 0; i < 2; i++) {
          int nx = x + kDx[i], ny = y + kDy[i];
          if (nx < n and ny < m) {
            res = max(res, profit + self(self, nx, ny, quota - 1));
          }
        }
      }
      int profit = coins[x][y];
      for (int i = 0; i < 2; i++) {
        int nx = x + kDx[i], ny = y + kDy[i];
        if (nx < n and ny < m) {
          res = max(res, profit + self(self, nx, ny, quota));
        }
      }
      return res;
      };
    return get_max_profit(get_max_profit, 0, 0, 2);
  }
};

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> coins(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> coins[i][j];
    }
  }
  Solution sol;
  cout << sol.maximumAmount(coins) << '\n';
  return 0;
}
