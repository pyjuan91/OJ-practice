#include <bits/stdc++.h>
#include "debug.cc"
using namespace std;

class Solution {
private:
  static const int kMax = 305;
  int dp[kMax][kMax] = {};
public:
  int longestSubsequence(vector<int>& nums) {
    int res = 0;
    for (const int& num : nums) {
      int greater_best = 0;
      for (int cur_diff = 299; cur_diff >= 0; cur_diff--) {
        int prev_left = num - cur_diff;
        int prev_right = num + cur_diff;
        if (prev_left >= 1) {
          greater_best = max(greater_best, dp[prev_left][cur_diff] + 1);
        }
        if (prev_right <= 300) {
          greater_best = max(greater_best, dp[prev_right][cur_diff] + 1);
        }
        dp[num][cur_diff] = greater_best;
        res = max(res, greater_best);
      }
    }
    return res;
  }
};

int main() {
  return 0;
}