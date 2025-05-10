#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int countPaths(vector<vector<int>>& grid) {
    constexpr int kMod = 1e9 + 7;
    constexpr int kDir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    size_t n = grid.size(), m = grid[0].size();
    vector dp(n, vector(m, 0));

    auto dfs = [&](auto&& self, int i, int j) -> int {
      if (dp[i][j]) return dp[i][j];
      dp[i][j] = 1;
      for (int d = 0; d < 4; ++d) {
        int ni = i + kDir[d][0], nj = j + kDir[d][1];
        if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
        if (grid[ni][nj] <= grid[i][j]) continue;
        dp[i][j] += self(self, ni, nj);
        dp[i][j] %= kMod;
      }
      return dp[i][j];
      };

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        ans += dfs(dfs, i, j);
        ans %= kMod;
      }
    }
    return ans;
  }
};

int main() { return 0; }