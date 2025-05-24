#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum + target < 0 || (sum + target) % 2 != 0) return 0;

    int kPosSum = (sum + target) / 2;
    vector<int> cnt(kPosSum + 1);
    cnt[0] = 1;

    for (int num : nums) {
      for (int j = kPosSum; j >= num; j--) {
        cnt[j] += cnt[j - num];
      }
    }

    return cnt[kPosSum];
  }
};

