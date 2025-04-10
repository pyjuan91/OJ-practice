#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  static constexpr int kMax = 10005;
  array<int, kMax> cnt, dp;
public:
  int deleteAndEarn(vector<int>& nums) {
    cnt.fill(0), dp.fill(0);
    for (const auto& num : nums) cnt[num]++;
    dp[1] = cnt[1];
    for (int i = 2; i < kMax; i++) {
      dp[i] = max(dp[i - 1], dp[i - 2] + i * cnt[i]);
    }
    return dp.back();
  }
};

int main() { return 0; }