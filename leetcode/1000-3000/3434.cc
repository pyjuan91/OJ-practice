#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxFrequency(vector<int>& nums, int k) {
    auto find_max_subarray_diff = [&](int target_value) -> int {
      int cur_diff = 0, max_diff = 0;
      for (auto num : nums) {
        if (num == target_value) cur_diff++;
        else if (num == k) cur_diff--;
        max_diff = max(max_diff, cur_diff);
        cur_diff = max(0, cur_diff);
      }
      return max_diff;
      };
    int max_diff = 0;
    for (int i = 1; i <= 50; i++) {
      if (i != k) max_diff = max(max_diff, find_max_subarray_diff(i));
    }
    return max_diff + count(nums.begin(), nums.end(), k);
  }
};

int main() {
  Solution s;
  return 0;
}