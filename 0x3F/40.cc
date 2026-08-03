#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> cur_candidates;
    map<int, int> cnt;
    for (const auto& candidate : candidates) cnt[candidate]++;
    int sum = 0;

    auto dfs = [&](this auto&& self, map<int, int>::iterator it) -> void {
      if (sum == target) {
        res.push_back(cur_candidates);
        return;
      }
      if (it == cnt.end()) return;
      for (int i = 1; i <= it->second; i++) {
        if (sum + it->first * i > target) break;
        for (int _ = 0; _ < i; _++) cur_candidates.push_back(it->first);
        sum += it->first * i;
        self(next(it));
        for (int _ = 0; _ < i; _++) cur_candidates.pop_back();
        sum -= it->first * i;
      }
      self(next(it));
    };

    dfs(cnt.begin());
    return vector<vector<int>>(res.begin(), res.end());
  }
};

int main() { return 0; }