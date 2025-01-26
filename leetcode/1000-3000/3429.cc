#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int64_t minCost(int32_t n, vector<vector<int32_t>>& cost) {
    const int64_t kInf = 1e12;
    vector<vector<vector<int64_t>>> dp(n, vector<vector<int64_t>>(4, vector<int64_t>(4, kInf)));
    auto find_min_cost = [&](auto&& self, size_t cur_idx, size_t prev_color, size_t post_color) -> int64_t {
      if (cur_idx == n / 2) return 0;
      int64_t& res = dp[cur_idx][prev_color][post_color];
      if (res != kInf) return res;
      size_t cur_jdx = n - cur_idx - 1;
      for (size_t i_color = 0; i_color < 3; i_color++) {
        for (size_t j_color = 0; j_color < 3; j_color++) {
          if (i_color == prev_color or j_color == post_color or i_color == j_color) continue;
          res = min(res, self(self, cur_idx + 1, i_color, j_color) + cost[cur_idx][i_color] + cost[cur_jdx][j_color]);
        }
      }
      return res;
      };
    return find_min_cost(find_min_cost, 0, 3, 3);
  }
};

int main() {
  Solution s;
  return 0;
}