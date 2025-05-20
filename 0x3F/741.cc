#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    vector dp(2, vector(n, vector(n, INT32_MIN)));
    dp[0][0][0] = grid[0][0];

    for (int step = 1; step <= 2 * n - 2; step++) {
      auto& cur = dp[step & 1];
      auto& prev = dp[(step - 1) & 1];

      cur.assign(n, vector(n, INT32_MIN));
      for (int i = max(0, step - (n - 1)); i <= min(n - 1, step); ++i) {
        int y1 = step - i;
        if (grid[i][y1] < 0) continue;
        for (int j = max(0, step - (n - 1)); j <= min(n - 1, step); ++j) {
          int y2 = step - j;
          if (grid[j][y2] < 0) continue;

          int best_prev = INT32_MIN;
          for (auto di1 : {0, 1}) {
            for (auto dj1 : {0, 1}) {
              int pi = i - di1;
              int pj = j - dj1;
              int py1 = (step - 1) - pi;
              int py2 = (step - 1) - pj;
              if (pi >= 0 and pj >= 0 and py1 >= 0 and py2 >= 0)
                best_prev = max(best_prev, prev[pi][pj]);
            }
          }

          if (best_prev < 0) continue;

          if (i == j)
            best_prev += grid[i][y1];
          else
            best_prev += grid[i][y1] + grid[j][y2];

          cur[i][j] = best_prev;
        }
      }
    }

    return max(0, dp[(2 * n - 2) & 1][n - 1][n - 1]);
  }
};