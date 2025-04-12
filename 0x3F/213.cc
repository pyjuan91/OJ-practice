#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    vector dp(n + 1, vector(2, 0));
    dp[1][1] = nums[0];
    for (int i = 2; i < n; i++) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 2][0] + nums[i - 1]);
      dp[i][1] = max(dp[i - 1][1], dp[i - 2][1] + nums[i - 1]);
    }
    dp[n][0] = max(dp[n - 1][0], dp[n - 2][0] + nums[n - 1]);
    dp[n][1] = dp[n - 1][1];
    return max(dp[n][0], dp[n][1]);
  }
};

int main() { return 0; }