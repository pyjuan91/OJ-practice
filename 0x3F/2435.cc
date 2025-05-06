#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int numberOfPaths(vector<vector<int>>& grid, int k) {
    constexpr int kMod = 1e9 + 7;
    size_t n = grid.size(), m = grid[0].size();
    vector dp(n, vector(m, vector(k, 0)));
    dp[0][0][grid[0][0] % k] = 1;
    for (size_t i = 0; i < n; ++i) {
      for (size_t j = 0; j < m; ++j) {
        if (i > 0) {
          for (int r = 0; r < k; ++r) {
            dp[i][j][(r + grid[i][j]) % k] += dp[i - 1][j][r];
            dp[i][j][(r + grid[i][j]) % k] %= kMod;
          }
        }
        if (j > 0) {
          for (int r = 0; r < k; ++r) {
            dp[i][j][(r + grid[i][j]) % k] += dp[i][j - 1][r];
            dp[i][j][(r + grid[i][j]) % k] %= kMod;
          }
        }
      }
    }
    return dp[n - 1][m - 1][0];
  }
};