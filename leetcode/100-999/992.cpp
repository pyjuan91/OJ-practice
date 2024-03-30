#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int subarraysWithKDistinct(vector<int>& nums, int k) {
    return woogie(nums, k - 1) - woogie(nums, k);
  }

 private:
  int woogie(vector<int>& nums, int k) {
    const int kMax = 2e4 + 5;
    int cnt[kMax] = {}, res = 0, l = 0, diff_cnt = 0;
    for (auto num : nums) {
      cnt[num]++;
      if (cnt[num] == 1) diff_cnt++;
      while (diff_cnt > k) {
        cnt[nums[l]]--;
        if (cnt[nums[l]] == 0) diff_cnt--;
        l++;
      }
      res += l;
    }
    return res;
  }
};
int main() {
  Solution s;
  vector<int> nums = {1, 2, 1, 2, 3};
  int k = 2;
  cout << s.subarraysWithKDistinct(nums, k) << endl;
  return 0;
}