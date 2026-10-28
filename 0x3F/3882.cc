#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minCost(vector<vector<int>>& grid) {
    const int n = grid.size(), m = grid[0].size();
    vector dp(n, vector(m, bitset<1024>()));
    dp[0][0][grid[0][0]].flip();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i == 0 and j == 0) continue;
        bitset<1024> prev_state;
        if (i > 0) {
          prev_state |= dp[i - 1][j];
        }
        if (j > 0) {
          prev_state |= dp[i][j - 1];
        }
        for (int k = 0; k < 1024; k++) {
          if (prev_state.test(k)) {
            dp[i][j].set(k ^ grid[i][j]);
          }
        }
      }
    }
    for (int k = 0; k < 1024; k++) {
      if (dp[n - 1][m - 1].test(k)) return k;
    }
    return -1;
  }
};

int main() { return 0; }