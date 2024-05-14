#include <bits/stdc++.h>
using namespace std;

class Solution {
  using vi = vector<int>;
  using vvi = vector<vi>;

 private:
  int dfs(int n, int m, vvi &grid, vvi &vis, int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || grid[i][j] == 0)
      return 0;
    vis[i][j] = true;
    int ans = 0;
    ans = max(ans, dfs(n, m, grid, vis, i + 1, j));
    ans = max(ans, dfs(n, m, grid, vis, i - 1, j));
    ans = max(ans, dfs(n, m, grid, vis, i, j + 1));
    ans = max(ans, dfs(n, m, grid, vis, i, j - 1));
    vis[i][j] = false;
    return ans + grid[i][j];
  }

 public:
  int getMaximumGold(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int ans = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!vis[i][j] && grid[i][j] != 0) {
          ans = max(ans, dfs(n, m, grid, vis, i, j));
        }
      }
    }

    return ans;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));
  for (auto &x : grid)
    for (auto &y : x) cin >> y;
  cout << Solution().getMaximumGold(grid) << '\n';
  return 0;
}