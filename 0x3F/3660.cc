#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> maxValue(vector<int>& nums) {
    const int n = nums.size();
    vector<int> pref_max(n), suff_min(n);
    for (int i = 0; i < n; i++) {
      pref_max[i] = (i == 0 ? nums[i] : max(pref_max[i - 1], nums[i]));
    }
    for (int i = n - 1; i >= 0; i--) {
      suff_min[i] = (i == n - 1 ? nums[i] : min(suff_min[i + 1], nums[i]));
    }
    vector<int> res(n);
    res[n - 1] = pref_max[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      if (pref_max[i] > suff_min[i + 1]) {
        res[i] = max(pref_max[i], res[i + 1]);
      } else {
        res[i] = pref_max[i];
      }
    }
    return res;
  }
};

int main() { return 0; }