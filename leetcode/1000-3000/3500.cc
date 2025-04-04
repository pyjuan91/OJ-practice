#include <bits/stdc++.h>
#include "debug.cc"
using namespace  std;
class Solution {
public:
  long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
    int n = nums.size();
    vector<long long> prefix_nums(n + 1, 0);
    vector<long long> prefix_cost(n + 1, 0);
    for (int i = 0; i < n; i++) {
      prefix_nums[i + 1] = prefix_nums[i] + nums[i];
      prefix_cost[i + 1] = prefix_cost[i] + cost[i];
    }

    vector<long long> dp(n + 2, INT64_MAX);
    dp[n + 1] = 0;
    for (int l = n; l >= 1; l--) {
      for (int r = n; r >= l; r--) {
        long long sum = prefix_nums[r] * (prefix_cost[r] - prefix_cost[l - 1]);
        sum += k * (prefix_cost[n] - prefix_cost[l - 1]);
        sum += dp[r + 1];
        dp[l] = min(dp[l], sum);
      }
    }
    return dp[1];
  }
};

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> nums(n), cost(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> cost[i];
  }
  Solution sol;
  cout << sol.minimumCost(nums, cost, k) << endl;
  return 0;
}