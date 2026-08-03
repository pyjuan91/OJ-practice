#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> cur_candidates;
    vector<pair<int, int>> groups;
    {
      map<int, int> cnt_;
      for (const auto& x : candidates) cnt_[x]++;
      groups.assign(cnt_.begin(), cnt_.end());
    }
    int sum = 0;

    auto dfs = [&](this auto&& self, size_t idx) -> void {
      if (sum == target) {
        res.push_back(cur_candidates);
        return;
      }
      if (idx == groups.size()) return;
      int num = groups[idx].first, cnt = groups[idx].second;
      int i = 1;
      for (; i <= cnt and sum + num <= target; i++) {
        cur_candidates.push_back(num);
        sum += num;
        self(idx + 1);
      }
      i--;
      cur_candidates.resize(cur_candidates.size() - i);
      sum -= num * i;
      self(idx + 1);
    };

    dfs(0);
    return res;
  }
};

int main() { return 0; }