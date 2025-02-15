#include <bits/stdc++.h>
#include <debug.cc>
using namespace std;

class Solution {
public:
  int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
    static constexpr int kMod = 1e9 + 7;
    int n = grid.size(), m = grid[0].size();
    vector dp(n, vector(m, vector(16, -1)));
    auto count_path = [&](auto&& self, int x, int y, int xor_value) -> int {
      if (x == n - 1 and y == m - 1) {
        return xor_value == grid[x][y];
      }
      if (dp[x][y][xor_value] != -1) {
        return dp[x][y][xor_value];
      }
      int res = 0;
      if (x < n - 1) res = (res + self(self, x + 1, y, xor_value ^ grid[x][y])) % kMod;
      if (y < m - 1) res = (res + self(self, x, y + 1, xor_value ^ grid[x][y])) % kMod;
      return dp[x][y][xor_value] = res;
      };
    return count_path(count_path, 0, 0, k);
  }
};

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> grid(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }
  Solution s;
  cout << s.countPathsWithXorValue(grid, k) << endl;
  return 0;
}