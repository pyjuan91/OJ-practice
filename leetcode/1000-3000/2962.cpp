#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long countSubarrays(vector<int>& nums, int k) {
    using i64 = long long;
    int n = nums.size(), ma = *max_element(nums.begin(), nums.end());
    vector<int> pre_ma(n, 0);
    for (int i = 0; i < n; i++) {
      pre_ma[i] = (i == 0 ? 0 : pre_ma[i - 1]) + (nums[i] == ma);
    }
    i64 ans = 0LL;
    for (int i = 0; i < n; i++) {
      if (pre_ma[i] < k) continue;
      ans += (i64)(upper_bound(pre_ma.begin(), pre_ma.end(), pre_ma[i] - k) -
                   pre_ma.begin() + 1);
    }
    return ans;
  }
};
int main() {
  Solution s;
  int n, k;
  cin >> n >> k;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  cout << s.countSubarrays(nums, k) << endl;
  return 0;
}