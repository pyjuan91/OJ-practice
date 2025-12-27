#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  long long maximumTripletValue(vector<int>& nums) {
    int n = nums.size();
    int ma_i = nums[0];
    int best_diff = nums[0] - nums[1];
    long long res = 0;
    for (int i = 2; i < n; i++) {
      res = max(res, 1LL * nums[i] * best_diff);
      ma_i = max(ma_i, nums[i - 1]);
      best_diff = max(best_diff, ma_i - nums[i]);
    }

    return res;
  }
};

int main() { return 0; }