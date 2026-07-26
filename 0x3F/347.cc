#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (const auto& num : nums) freq[num]++;
    vector<vector<int>> buckets(nums.size() + 1);
    for (const auto& [num, f] : freq) {
      buckets[f].push_back(num);
    }
    vector<int> res;
    for (size_t i = nums.size(); i > 0 and res.size() < k; i--) {
      for (const auto& x : buckets[i]) {
        res.push_back(x);
        if (res.size() == k) break;
      }
    }
    return res;
  }
};

int main() { return 0; }