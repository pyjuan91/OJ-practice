#include <bits/stdc++.h>
#include "debug.cc"
using namespace std;

class MedianDeque {
private:
  multiset<int64_t> left, right;
  int64_t sum_left = 0, sum_right = 0;
  void balance() {
    if (left.size() > right.size() + 1) {
      sum_left -= *left.rbegin();
      sum_right += *left.rbegin();
      right.insert(*left.rbegin());
      left.erase(left.find(*left.rbegin()));
    }
    else if (right.size() > left.size()) {
      sum_right -= *right.begin();
      sum_left += *right.begin();
      left.insert(*right.begin());
      right.erase(right.find(*right.begin()));
    }
  }
public:
  void insert(int64_t x) {
    if (left.empty() or x <= *left.rbegin()) {
      left.insert(x);
      sum_left += x;
    }
    else {
      right.insert(x);
      sum_right += x;
    }
    balance();
  }
  void erase(int64_t x) {
    if (left.count(x)) {
      left.erase(left.find(x));
      sum_left -= x;
    }
    else {
      right.erase(right.find(x));
      sum_right -= x;
    }
    balance();
  }
  int64_t get_median() {
    if (left.size() > right.size()) {
      return *left.rbegin();
    }
    else {
      return (*left.rbegin() + *right.begin()) / 2;
    }
  }
  int64_t get_cost() {
    int64_t res = get_median() * static_cast<int64_t>(left.size()) - sum_left;
    res += sum_right - get_median() * static_cast<int64_t>(right.size());
    return res;
  }
};

class Solution {
public:
  long long minOperations(vector<int>& nums, int x, int k) {
    int n = nums.size();
    nums.insert(nums.begin(), 0);
    // pair<int, int> means (median, cost_to_median)
    vector<pair<int64_t, int64_t>> median_cost(n + 1);
    auto median_deque = MedianDeque();
    for (int i = 0; i <= n; i++) {
      median_deque.insert(static_cast<int64_t>(nums[i]));
      int64_t median = median_deque.get_median();
      int64_t cost = median_deque.get_cost();
      median_cost[i] = { median, cost };
      if (i - x + 1 >= 0) {
        median_deque.erase(nums[i - x + 1]);
      }
    }
    // debug(median_cost);
    vector dp(n + 1, vector<int64_t>(k + 1, INT64_MAX >> 2));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= k; j++) {
        dp[i][j] = min(dp[i][j], dp[i - 1][j]);
        if (j > 0 and i - x >= 0) {
          dp[i][j] = min(dp[i][j], dp[i - x][j - 1] + median_cost[i].second);
          // debug(i, median_cost[i].first, median_cost[i].second);
        }
        // debug(i, j, dp[i][j]);
      }
    }
    int64_t res = INT64_MAX;
    for (int i = 0; i <= n; i++) {
      if (dp[i][k] != INT64_MAX) {
        res = min(res, dp[i][k]);
      }
    }
    return res;
  }
};


int main() {
  int n, x, k;
  cin >> n >> x >> k;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  Solution sol;
  cout << sol.minOperations(nums, x, k) << endl;
  return 0;
}