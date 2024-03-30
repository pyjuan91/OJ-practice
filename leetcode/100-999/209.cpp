#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int l = 0, r = 0, sum = 0, res = INT32_MAX;
    while (r < nums.size()) {
      sum += nums[r];
      while (sum >= target) {
        res = min(res, r - l + 1);
        sum -= nums[l];
        l++;
      }
      r++;
    }
    return res == INT32_MAX ? 0 : res;
  }
};
int main() {
  int n, target;
  cin >> n >> target;
  vector<int> nums(n);
  for (auto& num : nums) cin >> num;
  Solution s;
  cout << s.minSubArrayLen(target, nums) << endl;
  return 0;
}