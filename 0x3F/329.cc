#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
  const array<int, 4> dx = {1, -1, 0, 0};
  const array<int, 4> dy = {0, 0, 1, -1};

 public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector dp(n, vector(m, 0));

    auto solve = [&](auto&& self, int i, int j) -> int {
      if (dp[i][j]) return dp[i][j];
      int res = 1;
      for (int k = 0; k < 4; k++) {
        int ni = i + dx[k], nj = j + dy[k];
        if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
        if (matrix[ni][nj] <= matrix[i][j]) continue;
        res = max(res, self(self, ni, nj) + 1);
      }
      return dp[i][j] = res;
    };

    int res = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        res = max(res, solve(solve, i, j));
      }
    }
    return res;
  }
};

int main() { return 0; }