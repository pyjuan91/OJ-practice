#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    for (int i = 1; i < n; i++) {
      vector<int> suf_min(n + 1, INT32_MAX);
      for (int k = n - 1; k >= 0; k--) {
        suf_min[k] = min(suf_min[k + 1], grid[i - 1][k]);
      }
      int pref_min = INT32_MAX;
      for (int j = 0; j < n; j++) {
        grid[i][j] += min(suf_min[j + 1], pref_min);
        pref_min = min(pref_min, grid[i - 1][j]);
      }
    }
    return *min_element(grid.back().begin(), grid.back().end());
  }
};