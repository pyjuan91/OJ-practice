#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<__int128_t> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= target; i++) {
      for (int num : nums) {
        if (i - num >= 0) {
          dp[i] += dp[i - num];
        }
      }
    }

    return static_cast<int>(dp[target]);
  }
};

int main() {
  return 0;
}