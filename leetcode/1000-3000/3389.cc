#include <bits/stdc++.h>

#include "debug.cc"
using namespace std;

class Solution {
 private:
  static constexpr int kAlphabetSize = 26;

 public:
  int makeStringGood(string s) {
    vector item_freq(kAlphabetSize, 0);
    for (const char& c : s) item_freq[c - 'a']++;
    int max_freq = *max_element(item_freq.begin(), item_freq.end());
    int min_steps = static_cast<int>(s.size()) - max_freq;

    for (int target_freq = 1; target_freq <= max_freq; target_freq++) {
      vector dp(kAlphabetSize, unordered_map<int, int>());
      auto GetMinSteps = [&](auto&& self, int item_id, int prev_quota) -> int {
        if (item_id == kAlphabetSize) return 0;
        if (dp[item_id].count(prev_quota)) return dp[item_id][prev_quota];
        int& res = dp[item_id][prev_quota];
        // Case: No Modification Needed.
        if (item_freq[item_id] == 0 or item_freq[item_id] == target_freq)
          return res = self(self, item_id + 1, 0);
        // Case: Current Frequency Exceeds the Desired Count.
        if (item_freq[item_id] > target_freq)
          return res =
                     item_freq[item_id] - target_freq +
                     self(self, item_id + 1, item_freq[item_id] - target_freq);
        // Case: Current Frequency is Less Than the Desired Count (Setting Current to Zero)
        int kase_make_current_to_zero =
            item_freq[item_id] + self(self, item_id + 1, item_freq[item_id]);
        // Case: Current Frequency is Less Than the Desired Count (Setting Current to the Desired Count)
        int kase_add_current_to_target =
            max(0, target_freq - (item_freq[item_id] + prev_quota)) +
            self(self, item_id + 1, 0);
        return res = min(kase_make_current_to_zero, kase_add_current_to_target);
      };
      min_steps = min(min_steps, GetMinSteps(GetMinSteps, 0, 0));
    }
    return min_steps;
  }
};

int main() {
  Solution s;
  string str;
  cin >> str;
  cout << s.makeStringGood(str) << endl;
  return 0;
}