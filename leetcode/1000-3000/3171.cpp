#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minimumDifference(vector<int>& nums, int k) {
    int res = INT32_MAX;
    unordered_set<int> pref_and_stuffs;
    for (auto& num : nums) {
      unordered_set<int> new_pref_and_stuffs;
      for (auto& pref_and_stuffs_num : pref_and_stuffs) {
        new_pref_and_stuffs.insert(num & pref_and_stuffs_num);
        res = min(res, abs(k - (num & pref_and_stuffs_num)));
      }
      new_pref_and_stuffs.insert(num);
      res = min(res, abs(k - num));
      pref_and_stuffs = std::move(new_pref_and_stuffs);
    }
    return res;
  }
};
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  Solution sol;
  cout << sol.minimumDifference(nums, k) << endl;
}