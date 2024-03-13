#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int constrainedSubsetSum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> dp(n);
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++) {
      dp[i] = nums[i];
      while (!pq.empty() && pq.top().second < i - k) pq.pop();
      if (!pq.empty() && pq.top().first > 0) dp[i] += pq.top().first;
      pq.push({dp[i], i});
    }
    return *max_element(dp.begin(), dp.end());
  }
};
int main() { return 0; }