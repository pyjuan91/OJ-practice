#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int firstUniqueFreq(vector<int>& nums) {
    unordered_map<int, int> num_freq, freq_cnt;
    for (const auto& num : nums) {
      num_freq[num]++;
    }
    for (const auto& [k, v] : num_freq) {
      freq_cnt[v]++;
    }
    for (const auto& num : nums) {
      if (freq_cnt[num_freq[num]] == 1) {
        return num;
      }
    }
    return -1;
  }
};

int main() { return 0; }