#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int firstStableIndex(vector<int>& nums, int k) {
    const int n = nums.size();
    vector<int> pre_max(n), suff_min(n);
    pre_max[0] = nums[0];
    for (int i = 1; i < n; i++) pre_max[i] = max(pre_max[i - 1], nums[i]);
    suff_min[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
      suff_min[i] = min(suff_min[i + 1], nums[i]);
    for (int i = 0; i < n; i++) {
      if (pre_max[i] - suff_min[i] <= k) return i;
    }
    return -1;
  }
};

int main() { return 0; }