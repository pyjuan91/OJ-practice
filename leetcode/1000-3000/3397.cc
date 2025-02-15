#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxDistinctElements(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    nums[0] -= k;
    for (int i = 1; i < static_cast<int>(nums.size()); i++) {
      if (nums[i - 1] + 1 <= nums[i]) {
        nums[i] = max(nums[i - 1] + 1, nums[i] - k);
      }
      else {
        nums[i] = min(nums[i - 1] + 1, nums[i] + k);
      }
    }
    return static_cast<int>(unique(nums.begin(), nums.end()) - nums.begin());
  }
};

int main() {
  return 0;
}