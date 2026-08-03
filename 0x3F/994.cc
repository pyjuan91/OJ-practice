#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    // x-cord, y-cord, minute
    queue<tuple<int, int, int>> q;

    int cnt_fresh = 0;
    const int n = grid.size(), m = grid[0].size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 2) {
          q.push(make_tuple(i, j, 0));
        }
        if (grid[i][j] == 1) {
          cnt_fresh++;
        }
      }
    }

    if (cnt_fresh == 0) return 0;

    int last = -1;
    const array<int, 4> dx = {-1, 1, 0, 0};
    const array<int, 4> dy = {0, 0, -1, 1};
    while (!q.empty()) {
      auto [x, y, d] = q.front();
      last = d;
      q.pop();

      for (size_t i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 and nx < n and ny >= 0 and ny < m and grid[nx][ny] == 1) {
          cnt_fresh--;
          grid[nx][ny] = 2;
          q.push(make_tuple(nx, ny, d + 1));
        }
      }
    }

    return cnt_fresh == 0 ? last : -1;
  }
};

int main() { return 0; }