#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int64_t countQuadruplets(vector<int32_t>& nums) {
    const int32_t n = nums.size();
    // pref[i][j] means the count of elements that before index j and smaller
    // than i
    vector pref(n + 1, vector(n + 1, (int64_t)0));
    // suff[i][j] means the count of elements that after index j and greater
    // than i
    vector suff(n + 1, vector(n + 1, (int64_t)0));
    // precompute pref
    for (int32_t i = 2; i <= n; i++) {
      for (int32_t j = 0; j < n; j++) {
        pref[i][j + 1] = pref[i][j] + (nums[j] < i);
      }
    }
    // precompute suff
    for (int32_t i = 2; i <= n; i++) {
      for (int32_t j = n - 1; j >= 0; j--) {
        suff[i][j] = suff[i][j + 1] + (nums[j] > i);
      }
    }

    int64_t res = 0;
    for (int32_t j = 1; j < n - 2; j++) {
      for (int32_t k = j + 1; k < n - 1; k++) {
        if (nums[k] < nums[j]) {
          res += pref[nums[k]][j] * suff[nums[j]][k];
        }
      }
    }
    return res;
  }
};

int main() { return 0; }