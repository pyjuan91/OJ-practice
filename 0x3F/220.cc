#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff,
                                     int valueDiff) {
    int n = nums.size();
    multiset<int> ms;
    for (int i = 0; i < nums.size(); i++) {
      if (i > indexDiff) {
        ms.erase(ms.find(nums[i - 1 - indexDiff]));
      }
      auto it = ms.lower_bound(nums[i]);
      if (it != ms.end() and *it - nums[i] <= valueDiff) return true;
      if (it != ms.begin() and nums[i] - *(prev(it)) <= valueDiff) return true;
      ms.insert(nums[i]);
    }
    return false;
  }
};

int main() { return 0; }