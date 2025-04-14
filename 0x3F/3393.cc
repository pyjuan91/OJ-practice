#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  static constexpr int kMod = 1e9 + 7;

 public:
  int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
    size_t n = grid.size(), m = grid[0].size();
    vector dp(n, vector(m, vector(16, 0)));
    dp[0][0][grid[0][0]] = 1;
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < m; j++) {
        for (size_t x = 0; x < 16; x++) {
          if (i == 0 and j == 0) continue;
          if (i == 0) {
            dp[i][j][x ^ grid[i][j]] += dp[i][j - 1][x];
            dp[i][j][x ^ grid[i][j]] %= kMod;
          } else if (j == 0) {
            dp[i][j][x ^ grid[i][j]] += dp[i - 1][j][x];
            dp[i][j][x ^ grid[i][j]] %= kMod;
          } else {
            dp[i][j][x ^ grid[i][j]] +=
                (dp[i - 1][j][x] + dp[i][j - 1][x]) % kMod;
            dp[i][j][x ^ grid[i][j]] %= kMod;
          }
        }
      }
    }
    return dp[n - 1][m - 1][k] % kMod;
  }
};

int main() { return 0; }