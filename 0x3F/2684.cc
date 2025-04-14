#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxMoves(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    bitset<1001> dp, next_dp;
    for (int i = 0; i < n; i++) {
      dp.set(i);
    }
    for (int j = 1; j < m; j++) {
      for (int i = 0; i < n; i++) {
        bitset<3> valid;
        array<int, 3> next = {i - 1, i, i + 1};
        for (int k = 0; k < 3; k++) {
          if (next[k] >= 0 and next[k] < n and
              grid[next[k]][j - 1] < grid[i][j] and dp[next[k]]) {
            valid.set(k);
          }
        }
        if (valid.any()) next_dp.set(i);
      }
      if (!next_dp.any()) return j - 1;
      dp = next_dp;
      next_dp.reset();
    }
    return m - 1;
  }
};

int main() { return 0; }