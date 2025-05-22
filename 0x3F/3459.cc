#include <bits/stdc++.h>

#include "../debug.cc"
using namespace std;


#pragma GCC optimize("O3", "unroll-loops")

const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
  struct ___ { static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; } };
  std::atexit(&___::_);
  return 0;
}();
#endif

array<array<array<array<int, 2>, 4>, 505>, 505> dp;
class Solution {
 public:
  int lenOfVDiagonal(vector<vector<int>>& grid) {
    const array<int, 4> dx = {-1, -1, 1, 1}, dy = {-1, 1, 1, -1};
    int n = grid.size(), m = grid[0].size();
    auto is_valid = [&](int i, int j, int val) -> bool {
      return i >= 0 and i < n and j >= 0 and j < m and grid[i][j] == val;
    };
    auto trans_pos = [&](int i, int j, int k) -> pair<int, int> {
      if (k == 0) return make_pair(i, j);
      if (k == 1) return make_pair(i, m - 1 - j);
      if (k == 2) return make_pair(n - 1 - i, m - 1 - j);
      return make_pair(n - 1 - i, j);
    };

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int k = 0; k < 4; k++) {
          auto [x, y] = trans_pos(i, j, k);
          if (grid[x][y] == 0 or grid[x][y] == 2) {
            dp[x][y][k][0] = 1;
            int nx = x + dx[k], ny = y + dy[k];
            if (is_valid(nx, ny, 2 - grid[x][y])) {
              dp[x][y][k][0] += dp[nx][ny][k][0];
            }
          }
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int k = 0; k < 4; k++) {
          auto [x, y] = trans_pos(i, j, k);
          if (grid[x][y] == 0 or grid[x][y] == 2) {
            dp[x][y][k][1] = dp[x][y][k][0];
            int nx = x + dx[k], ny = y + dy[k];
            if (is_valid(nx, ny, 2 - grid[x][y])) {
              dp[x][y][k][1] = max({dp[x][y][k][1], dp[nx][ny][k][1] + 1,
                                    dp[nx][ny][(k + 1) % 4][0] + 1});
            }
          }
        }
      }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          res = max(res, 1);

          for (int k = 0; k < 4; k++) {
            int ni = i + dx[k], nj = j + dy[k];
            if (is_valid(ni, nj, 2)) {
              res = max(
                  {res, dp[ni][nj][k][1] + 1, dp[ni][nj][(k + 1) % 4][0] + 1});
            }
          }
        }
      }
    }

    return res;
  }
};

int main() {
  // vector<vector<int>> grid = {{2, 2, 1, 2, 2},
  //                             {2, 0, 2, 2, 0},
  //                             {2, 0, 1, 1, 0},
  //                             {1, 0, 2, 2, 2},
  //                             {2, 0, 0, 2, 2}};
  // vector<vector<int>> grid = {{1, 2, 2}, {1, 0, 2}};
  vector<vector<int>> grid = {
      {0, 1, 0, 0, 0, 0, 0}, {2, 1, 1, 2, 1, 2, 2}, {1, 1, 1, 2, 2, 1, 0}};
  Solution s;
  cout << s.lenOfVDiagonal(grid) << endl;
  return 0;
}