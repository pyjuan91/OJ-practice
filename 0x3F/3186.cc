#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  long long maximumTotalDamage(vector<int>& power) {
    map<long long, long long> discreted;
    for (const auto& p : power) discreted[p] = 0;
    long long idx = 0;
    for (auto& [x, y] : discreted) {
      y = idx++;
    }
    vector<long long> recovered(idx);
    for (const auto& [x, y] : discreted) recovered[y] = x;
    vector<long long> cnt(idx, 0);
    for (const auto& p : power) cnt[discreted[p]]++;
    vector<long long> dp(idx, 0);
    dp[0] = cnt[0] * recovered[0];
    for (long long i = 1; i < idx; i++) {
      if (recovered[i - 1] < recovered[i] - 2) {
        dp[i] = dp[i - 1] + cnt[i] * recovered[i];
        continue;
      }
      if (i - 2 >= 0 and recovered[i - 2] < recovered[i] - 2) {
        dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i] * recovered[i]);
        continue;
      }
      dp[i] = max({dp[i - 1], (i - 2 >= 0 ? dp[i - 2] : 0LL),
                   (i - 3 >= 0 ? dp[i - 3] : 0LL) + cnt[i] * recovered[i]});
    }
    return dp[idx - 1];
  }
};

int main() { return 0; }