#include <bits/stdc++.h>
using namespace std;

class Solution {
<<<<<<< HEAD
 public:
  int maxProductPath(vector<vector<int>>& grid) {
    constexpr int MOD = 1'000'000'007;
    int n = grid.size(), m = grid[0].size();
    // Use long long so INT64_MIN / INT64_MAX make sense
    vector<vector<long long>> max_dp(n, vector<long long>(m, LLONG_MIN));
    vector<vector<long long>> min_dp(n, vector<long long>(m, LLONG_MAX));

    // Base case
    max_dp[0][0] = min_dp[0][0] = grid[0][0];

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (i == 0 && j == 0) continue;
        long long val = grid[i][j];

        long long cur_max = LLONG_MIN;
        long long cur_min = LLONG_MAX;

        // From above
        if (i > 0) {
          long long p1 = max_dp[i - 1][j] * val;
          long long p2 = min_dp[i - 1][j] * val;
          cur_max = max(cur_max, max(p1, p2));
          cur_min = min(cur_min, min(p1, p2));
        }
        // From left
        if (j > 0) {
          long long p1 = max_dp[i][j - 1] * val;
          long long p2 = min_dp[i][j - 1] * val;
          cur_max = max(cur_max, max(p1, p2));
          cur_min = min(cur_min, min(p1, p2));
        }

        max_dp[i][j] = cur_max;
        min_dp[i][j] = cur_min;
      }
    }

    long long result = max_dp[n - 1][m - 1];
    if (result < 0) return -1;
    return result % MOD;
  }
};
=======
public:
  int maxProductPath(vector<vector<int>>& grid) {
    constexpr int kMod = 1e9 + 7;
    size_t n = grid.size(), m = grid[0].size();
    vector max_dp(n, vector(m, INT64_MIN));
    vector min_dp(n, vector(m, INT64_MAX));
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < m; j++) {
        if (i == 0 and j == 0) {
          max_dp[i][j] = min_dp[i][j] = grid[i][j];
        }
        else {
          int maj = j > 0 ? max(max_dp[i][j - 1] * grid[i][j], min_dp[i][j - 1] * grid[i][j]) : INT64_MIN;
          int mij = j > 0 ? min(max_dp[i][j - 1] * grid[i][j], min_dp[i][j - 1] * grid[i][j]) : INT64_MAX;

          int mai = i > 0 ? max(max_dp[i - 1][j] * grid[i][j], min_dp[i - 1][j] * grid[i][j]) : INT64_MIN;
          int mii = i > 0 ? min(max_dp[i - 1][j] * grid[i][j], min_dp[i - 1][j] * grid[i][j]) : INT64_MAX;

          max_dp[i][j] = max(maj, mai);
          min_dp[i][j] = min(mij, mii);

        }
        cout << "max_dp[" << i << "][" << j << "] = " << max_dp[i][j] << endl;
        cout << "min_dp[" << i << "][" << j << "] = " << min_dp[i][j] << endl;
      }
    }
    if (max_dp[n - 1][m - 1] < 0) return -1;
    return max_dp[n - 1][m - 1] % kMod;
  }
};

int main() {
  return 0;
}
>>>>>>> d6b1057 (lc 1594)
