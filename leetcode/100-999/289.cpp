#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  void gameOfLife(vector<vector<int>>& board) {
    int n = board.size(), m = board[0].size();
    const int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
    const int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
    auto is_valid = [&](int x, int y) -> bool {
      return x >= 0 && x < n && y >= 0 && y < m;
    };
    auto count_live_neighbors = [&](int x, int y) -> int {
      int cnt = 0;
      for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (is_valid(nx, ny) && (board[nx][ny] & 1)) cnt++;
      }
      return cnt;
    };
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == 1) {
          int cnt = count_live_neighbors(i, j);
          if (cnt >= 2 && cnt <= 3) board[i][j] |= 2;
        } else {
          if (count_live_neighbors(i, j) == 3) {
            board[i][j] |= 2;
          }
        }
      }
    }
    for (auto& row : board) {
      for (auto& cell : row) cell >>= 1;
    }
  }
};
int main() {
  Solution s;
  vector<vector<int>> board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
  s.gameOfLife(board);
  for (auto& row : board) {
    for (auto& cell : row) cout << cell << " ";
    cout << endl;
  }
  return 0;
}