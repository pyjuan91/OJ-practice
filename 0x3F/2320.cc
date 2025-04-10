#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  static constexpr int kMod = 1e9 + 7;
  array<int, 4> dp, dp_next;
public:
  int countHousePlacements(int n) {
    dp = { 1, 0, 0, 0 };
    for (int i = 1; i <= n; i++) {
      dp_next.fill(0);
      for (int j = 0; j < 4; j++) dp_next[0] = (dp_next[0] + dp[j]) % kMod;
      dp_next[1] = (dp[0] + dp[2]) % kMod;
      dp_next[2] = (dp[0] + dp[1]) % kMod;
      dp_next[3] = dp[0];
      dp.swap(dp_next);
    }
    int ans = 0;
    for (int i = 0; i < 4; i++) ans = (ans + dp[i]) % kMod;
    return ans;
  }
};

int main() { return 0; }