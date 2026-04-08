#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> getBiggestThree(vector<vector<int>>& grid) {
    const int n = grid.size(), m = grid[0].size();
    set<int> rhombus_sums;
    for (int side_length = 0; side_length < 50; side_length++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          auto get_rhombus_sum = [&](int i, int j, int side_length) -> int {
            int left_most_index = j - side_length;
            int right_most_index = j + side_length;
            int lowest_index = i + 2 * side_length;
            if (left_most_index < 0 or right_most_index >= m or
                lowest_index >= n)
              return -1;

            int res =
                grid[i][j] + (side_length > 0 ? grid[lowest_index][j] : 0);
            // upper left wing + upper right wing
            // lower left wing + lower right wing
            for (int step = 1; step <= side_length; step++) {
              res += grid[i + step][j - step];
              res += grid[i + step][j + step];
              if (step == side_length) break;
              res += grid[lowest_index - step][j - step];
              res += grid[lowest_index - step][j + step];
            }
            return res;
          };

          int rs = get_rhombus_sum(i, j, side_length);
          if (rs != -1) rhombus_sums.insert(rs);
        }
      }
    }
    vector<int> res(rhombus_sums.begin(), rhombus_sums.end());
    reverse(res.begin(), res.end());
    if (res.size() > 3) res.resize(3);
    return res;
  }
};

int main() { return 0; }