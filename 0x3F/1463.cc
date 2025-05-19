#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();

    const array<int, 3> dir = {-1, 0, 1};
    vector dp_prv(m, vector(m, 0)), dp_cur(m, vector(m, 0));
    for (int i = 0; i < m; i++) {
      for (int j = i + 1; j < m; j++) {
        dp_prv[i][j] = grid[n - 1][i] + grid[n - 1][j];
      }
    }

    for (int row = n - 2; row >= 0; row--) {
      for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
          for (int d1 = 0; d1 < 3; d1++) {
            for (int d2 = 0; d2 < 3; d2++) {
              int ni = i + dir[d1];
              int nj = j + dir[d2];
              if (ni >= 0 and ni < nj and nj < m) {
                dp_cur[i][j] = max(dp_cur[i][j], dp_prv[ni][nj]);
              }
            }
          }
          dp_cur[i][j] += grid[row][i] + grid[row][j];
        }
      }
      dp_prv.assign(m, vector(m, 0));
      swap(dp_prv, dp_cur);
    }

    return dp_prv[0][m - 1];
  }
};