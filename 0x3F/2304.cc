#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
    size_t n = grid.size(), m = grid[0].size();
    vector dp(grid[0].begin(), grid[0].end()), next_dp(m, INT32_MAX);
    for (size_t row = 0; row < n - 1; row++) {
      for (size_t col = 0; col < m; col++) {
        int val = grid[row][col];
        for (size_t next_col = 0; next_col < m; next_col++) {
          int cost = moveCost[val][next_col] + grid[row + 1][next_col];
          next_dp[next_col] = min(next_dp[next_col], dp[col] + cost);
        }
      }
      dp.swap(next_dp);
      fill(next_dp.begin(), next_dp.end(), INT32_MAX);
    }

    return *min_element(dp.begin(), dp.end());
  }
};

int main() { return 0; }