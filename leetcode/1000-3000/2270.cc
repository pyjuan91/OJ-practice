#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int waysToSplitArray(vector<int>& nums) {
    size_t n = nums.size();
    vector<int64_t> prefix(n);
    prefix[0] = static_cast<int64_t>(nums[0]);
    for (size_t i = 1; i < n; ++i) {
      prefix[i] = prefix[i - 1] + nums[i];
    }
    int ans = 0;
    for (size_t i = 0; i < n - 1;i++) {
      if (prefix[i] >= prefix[n - 1] - prefix[i]) ans++;
    }
    return ans;
  }
};

int main() {
  return 0;
}