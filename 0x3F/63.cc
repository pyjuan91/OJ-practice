#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    size_t n = obstacleGrid.size(), m = obstacleGrid[0].size();
    vector dp(m, 0);
    dp[0] = 1;
    for (size_t i = 0; i < n; i++) {
      dp[0] &= 1 ^ obstacleGrid[i][0];
      for (size_t j = 1; j < m; j++) {
        if (obstacleGrid[i][j] == 1) {
          dp[j] = 0;
        } else {
          dp[j] += dp[j - 1];
        }
      }
    }
    return dp[m - 1];
  }
};

int main() { return 0; }