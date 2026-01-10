#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  bool patty(vector<vector<int32_t>>& grid) {
    int32_t n = grid.size(), m = grid[0].size();

    if (n == 1) {
      int64_t left_sum = 0, right_sum = 0;
      for (int i = 0; i < m; i++) right_sum += grid[0][i];
      for (int left = 0; left < m - 1; left++) {
        left_sum += grid[0][left];
        right_sum -= grid[0][left];
        if (right_sum == left_sum) {
          return true;
        } else if (right_sum > left_sum) {
          int64_t target = right_sum - left_sum;
          if (target > INT32_MAX) continue;
          if (grid[0][left + 1] == target or grid[0][m - 1] == target)
            return true;
        } else /*right_sum < left_sum */ {
          int64_t target = left_sum - right_sum;
          if (target > INT32_MAX) continue;
          if (grid[0][0] == target or grid[0][left] == target) return true;
        }
      }
      return false;
    }

    unordered_map<int, int> left_num, right_num;
    int64_t left_sum = 0, right_sum = 0;
    for (int32_t i = 0; i < n; i++) {
      for (int32_t j = 0; j < m; j++) {
        right_sum += grid[i][j];
        right_num[grid[i][j]]++;
      }
    }

    for (int32_t col = 0; col < m - 1; col++) {
      for (int32_t row = 0; row < n; row++) {
        left_num[grid[row][col]]++;
        right_num[grid[row][col]]--;
        if (right_num[grid[row][col]] == 0) {
          right_num.erase(grid[row][col]);
        }
        left_sum += grid[row][col];
        right_sum -= grid[row][col];
      }

      if (left_sum == right_sum) {
        return true;
      } else if (left_sum < right_sum) {
        int64_t target = right_sum - left_sum;
        if (target > INT32_MAX) continue;
        if (col == m - 2) {
          if (grid[0][m - 1] == target or grid[n - 1][m - 1] == target) {
            return true;
          }
        } else {
          if (right_num.count(target)) {
            return true;
          }
        }
      } else /* left_sum > right_sum*/ {
        int64_t target = left_sum - right_sum;
        if (target > INT32_MAX) continue;
        if (col == 0) {
          if (grid[0][0] == target or grid[n - 1][0] == target) {
            return true;
          }
        } else {
          if (left_num.count(target)) {
            return true;
          }
        }
      }
    }

    return false;
  }

 public:
  bool canPartitionGrid(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> trans_grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        trans_grid[i][j] = grid[j][i];
      }
    }
    return patty(grid) or patty(trans_grid);
  }
};

int main() { return 0; }