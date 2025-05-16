#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
 public:
  bool hasValidPath(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector dp(n, vector(m, bitset<101>()));

    if ((n + m) % 2 == 0) return false;
    if (grid[0][0] == '(')
      dp[0][0][1] = true;
    else
      return false;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (i > 0) {
          if (grid[i][j] == '(') {
            dp[i][j] |= (dp[i - 1][j] << 1);
          } else {
            dp[i][j] |= (dp[i - 1][j] >> 1);
          }
        }

        if (j > 0) {
          if (grid[i][j] == '(') {
            dp[i][j] |= (dp[i][j - 1] << 1);
          } else {
            dp[i][j] |= (dp[i][j - 1] >> 1);
          }
        }
      }
    }

    return dp[n - 1][m - 1][0];
  }
};

int main() { return 0; }