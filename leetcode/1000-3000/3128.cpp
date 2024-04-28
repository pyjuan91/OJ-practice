#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long numberOfRightTriangles(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<int> row_ones(n), col_ones(m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        row_ones[i] += grid[i][j], col_ones[j] += grid[i][j];
    }
    long long res = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 0) continue;
        res += (row_ones[i] - 1) * (col_ones[j] - 1);
      }
    }
    return res;
  }
};
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }
  Solution s;
  cout << s.numberOfRightTriangles(grid) << endl;
}