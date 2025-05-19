#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int maxCollectedFruits(vector<vector<int>>& fruits) {
    int n = fruits.size();
    int res = 0;

    vector dp(n, vector(n, -1));
    auto dfs = [&](auto&& self, int i, int j) -> int {
      if (j < n - 1 - i || j >= n) return INT32_MIN;
      if (i == 0) return fruits[i][j];
      int& res = dp[i][j];
      if (res != -1) return res;
      return res = max({self(self, i - 1, j), self(self, i - 1, j - 1),
                        self(self, i - 1, j + 1)}) +
                   fruits[i][j];
    };
    for (int i = 0; i < n; i++) res += fruits[i][i], fruits[i][i] = 0;
    res += dfs(dfs, n - 2, n - 1);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) fruits[i][j] = fruits[j][i];
    }
    dp.assign(n, vector(n, -1));
    res += dfs(dfs, n - 2, n - 1);
    return res;
  }
};