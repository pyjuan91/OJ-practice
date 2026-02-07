#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minRemoval(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    if (1LL * nums.front() * k >= nums.back()) return 0;
    int n = nums.size();
    int left = 1, right = n;
    while (left + 1 < right) {
      int mid = (left + right) / 2;
      bool ok = false;
      for (int i = mid - 1; i < n; i++) {
        if (1LL * nums[i - mid + 1] * k >= nums[i]) {
          ok = true;
          break;
        }
      }
      if (ok) {
        left = mid;
      } else {
        right = mid;
      }
    }
    return n - left;
  }
};

int main() { return 0; }