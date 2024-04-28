#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int numberOfStableArrays(int zero, int one, int limit) {
    const int kMod = 1e9 + 7;
    int dp[1001][1001][2];
    for (int i = 0; i <= zero; i++) {
      for (int j = 0; j <= one; j++) {
        int& dp0 = dp[i][j][0] = 0;
        int& dp1 = dp[i][j][1] = 0;
        if (i == 0) {
          dp1 = (j > 0 && j <= limit);
          continue;
        }
        if (j == 0) {
          dp0 = (i > 0 && i <= limit);
          continue;
        }
        dp0 = (dp[i - 1][j][0] + dp[i - 1][j][1]) % kMod;
        dp1 = (dp[i][j - 1][0] + dp[i][j - 1][1]) % kMod;
        if (i > limit) {
          dp0 -= dp[i - limit - 1][j][1];
          dp0 = (dp0 + kMod) % kMod;
        }
        if (j > limit) {
          dp1 -= dp[i][j - limit - 1][0];
          dp1 = (dp1 + kMod) % kMod;
        }
      }
    }
    return (dp[zero][one][0] + dp[zero][one][1]) % kMod;
  }
};

int main() {
  Solution s;
  int zero, one, limit;
  cin >> zero >> one >> limit;
  cout << s.numberOfStableArrays(zero, one, limit);
  return 0;
}