#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int countQuadruplets(vector<int>& nums) {
    int res = 0;
    const size_t n = nums.size();
    unordered_map<int, int> cnt_ab;
    for (int c = 2; c < n - 1; c++) {
      for (int a = 0; a < c - 1; a++) {
        cnt_ab[nums[a] + nums[c - 1]]++;
      }
      for (int d = c + 1; d < n; d++) {
        int diff = nums[d] - nums[c];
        if (cnt_ab.count(diff)) res += cnt_ab[diff];
      }
    }
    return res;
  }
};

int main() { return 0; }