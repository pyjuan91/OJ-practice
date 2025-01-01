#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumOperations(vector<vector<int>>& grid) {
    int res = 0;
    for (size_t col_idx = 0; col_idx < grid[0].size(); col_idx++) {
      for (size_t row_idx = 1; row_idx < grid.size(); row_idx++) {
        if (grid[row_idx][col_idx] <= grid[row_idx - 1][col_idx]) {
          res += grid[row_idx - 1][col_idx] - grid[row_idx][col_idx] + 1;
          grid[row_idx][col_idx] = grid[row_idx - 1][col_idx] + 1;
        }
      }
    }
    return res;
  }
};

int main() {
  return 0;
}