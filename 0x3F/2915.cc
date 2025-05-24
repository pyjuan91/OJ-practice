#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int lengthOfLongestSubsequence(vector<int>& nums, int target) {
    vector<int> cnt(target + 1);
    for (const auto& num : nums) {
      for (int i = target; i >= num; i--) {
        if (cnt[i - num]) {
          cnt[i] = max(cnt[i], cnt[i - num] + 1);
        }
      }
      if (num <= target) cnt[num] = max(cnt[num], 1);
    }
    return cnt[target] ? cnt[target] : -1;
  }
};

int main() {
  vector<int> nums = {4, 1, 3, 2, 1, 5};
  int target = 7;
  Solution s;
  cout << s.lengthOfLongestSubsequence(nums, target) << endl;
}