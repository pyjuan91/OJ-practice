#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int specialTriplets(vector<int>& nums) {
    const int kMod = 1e9 + 7;
    unordered_map<int, int> tot_cnt;
    unordered_map<int, int> left_cnt;
    for (const auto& x : nums) tot_cnt[x]++;

    int res = 0;
    for (const auto& x : nums) {
      int left_contrib = left_cnt.count(x * 2) ? left_cnt[x * 2] : 0;
      int right_contrib =
          tot_cnt.count(x * 2) ? tot_cnt[x * 2] - left_contrib : 0;
      if (x == 0 and right_contrib) right_contrib--;
      res = (1LL * res + (1LL * left_contrib * right_contrib % kMod)) % kMod;
      left_cnt[x]++;
    }

    return res;
  }
};

int main() { return 0; }