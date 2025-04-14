#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    size_t n = grid.size(), m = grid[0].size();
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < m; j++) {
        if (i == 0 and j == 0) continue;
        if (i == 0) {
          grid[i][j] += grid[i][j - 1];
        } else if (j == 0) {
          grid[i][j] += grid[i - 1][j];
        } else {
          grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        }
      }
    }
    return grid[n - 1][m - 1];
  }
};

int main() { return 0; }