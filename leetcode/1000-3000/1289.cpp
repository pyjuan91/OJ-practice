#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    if (n == 1) return grid[0][0];
    vector<int> dp_cur(n, INT32_MAX), dp_prev(n, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          if (k == j) continue;
          dp_cur[j] = min(dp_cur[j], dp_prev[k] + grid[i][j]);
        }
      }
      dp_prev = dp_cur;
      dp_cur.assign(n, INT32_MAX);
    }
    return *min_element(dp_prev.begin(), dp_prev.end());
  }
};
int main() {
  Solution s;
  int n;
  cin >> n;
  vector<vector<int>> grid(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }
  cout << s.minFallingPathSum(grid) << endl;
  return 0;
}