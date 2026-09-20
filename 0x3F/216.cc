#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> cur;

    auto dfs = [&](this auto& self, int cur_sum, int cur_cnt, int cur_num) {
      if (cur_cnt == k) {
        if (cur_sum == n) {
          res.push_back(cur);
        }
        return;
      }
      if (cur_sum >= n or cur_num > 9) return;
      cur.push_back(cur_num);
      self(cur_sum + cur_num, cur_cnt + 1, cur_num + 1);
      cur.pop_back();
      self(cur_sum, cur_cnt, cur_num + 1);
    };

    dfs(0, 0, 1);
    return res;
  }
};

int main() { return 0; }