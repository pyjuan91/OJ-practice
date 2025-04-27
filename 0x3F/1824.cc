#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int minSideJumps(vector<int>& obstacles) {
    size_t n = obstacles.size();
    constexpr int kInf = INT32_MAX >> 2;
    vector dp(n, array<int, 4>{kInf, kInf, kInf, kInf});
    dp[0][2] = 0;
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 1; j <= 3; j++) {
        if (obstacles[i] != j) {
          if (i) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
          for (size_t k = 1; k <= 3; k++) {
            if (k != j) dp[i][j] = min(dp[i][j], dp[i][k] + 1);
          }
          for (size_t k = 1; k <= 3; k++) {
            if (k != j and obstacles[i] != k) {
              dp[i][k] = min(dp[i][k], dp[i][j] + 1);
            }
          }
        }
      }
    }

    return min({ dp[n - 1][1], dp[n - 1][2], dp[n - 1][3] });
  }
};

int main() {
  return 0;
}