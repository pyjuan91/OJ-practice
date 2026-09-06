#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    const int n = nums.size();
    vector<int> res(n, INT32_MIN);
    vector<pair<int, int>> mono_stack;
    for (int i = 0; i < n * 2; i++) {
      while (not mono_stack.empty() and
             nums[i % n] > mono_stack.back().second) {
        auto [idx, value] = mono_stack.back();
        mono_stack.pop_back();
        if (res[idx] == INT32_MIN) {
          res[idx] = nums[i % n];
        }
      }
      mono_stack.push_back(make_pair(i % n, nums[i % n]));
    }
    for (int i = 0; i < n; i++) {
      if (res[i] == INT32_MIN) res[i] = -1;
    }
    return res;
  }
};

int main() { return 0; }