#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maximumAmount(vector<vector<int>>& coins) {
    int n = coins.size(), m = coins[0].size();
    auto dp = vector(n, vector(m, vector(3, static_cast<int>(INT32_MIN))));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int k = 0; k < 3; k++) {
          int up = (i > 0 ? dp[i - 1][j][k] : INT32_MIN);
          int left = (j > 0 ? dp[i][j - 1][k] : INT32_MIN);
          if (i > 0 or j > 0)
            dp[i][j][k] = coins[i][j] + max(up, left);
          else
            dp[i][j][k] = coins[i][j];
          if (coins[i][j] < 0 and k > 0) {
            int up = (i > 0 ? dp[i - 1][j][k - 1] : INT32_MIN);
            int left = (j > 0 ? dp[i][j - 1][k - 1] : INT32_MIN);
            if (i > 0 or j > 0)
              dp[i][j][k] = max(dp[i][j][k], max(up, left));
            else
              dp[i][j][k] = max(dp[i][j][k], 0);
          }
        }
      }
    }
    return max({
        dp[n - 1][m - 1][0],
        dp[n - 1][m - 1][1],
        dp[n - 1][m - 1][2],
    });
  }
};

int main() { return 0; }