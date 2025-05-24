#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    size_t n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum & 1) return false;
    sum /= 2;

    vector<bool> reachable(sum + 1, false);
    reachable[0] = true;
    for (size_t i = 0; i < n; i++) {
      for (int j = sum; j >= nums[i]; j--) {
        reachable[j] = reachable[j] || reachable[j - nums[i]];
      }
    }

    return reachable[sum];
  }
};