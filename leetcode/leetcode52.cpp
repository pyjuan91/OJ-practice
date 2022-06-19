#include <iostream>
#include <vector>
using namespace std;
int board[10][10];
int ans;
class Solution {
public:
  int totalNQueens(int n) {
    // init
    ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        board[i][j] = 0;
      }
    }
    queen(0, n);
    return ans;
  }
  void queen(int now, int all) {
    if (now == all) {
      ans++;
      return;
    }
    for (int i = 0; i < all; i++) {
      if (checkAndPlace(now, i, all)) {
        // cout << now << " " << i << endl;
        // printBoard(all);
        queen(now + 1, all);
      }
      clear(now, i, all);
    }
  }
  void clear(int x, int y, int all) { board[x][y] = 0; }
  bool checkAndPlace(int x, int y, int all) {
    for (int i = 0; i < all; i++) {
      for (int j = 0; j < all; j++) {
        if ((i + j == x + y || i - j == x - y || i == x || j == y) &&
            board[i][j])
          return false;
      }
    }
    board[x][y] = 1;
    return true;
  }
  void printBoard(int all) {
    for (int i = 0; i < all; i++) {
      for (int j = 0; j < all; j++) {
        cout << board[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
};
// class Solution {
// public:
//   int totalNQueens(int n) {
//     vector<bool> col(n), diag(2 * n - 1), anti_diag(2 * n - 1);
//     return solve(col, diag, anti_diag, 0);
//   }

//   int solve(vector<bool> &col, vector<bool> &diag, vector<bool> &anti_diag,
//             int row) {
//     int n = size(col), count = 0;
//     if (row == n)
//       return 1;
//     for (int column = 0; column < n; column++)
//       if (!col[column] && !diag[row + column] &&
//           !anti_diag[row - column + n - 1]) {
//         col[column] = diag[row + column] = anti_diag[row - column + n - 1] =
//             true;
//         count += solve(col, diag, anti_diag, row + 1);
//         col[column] = diag[row + column] = anti_diag[row - column + n - 1] =
//             false;
//       }
//     return count;
//   }
// };
int main(void) {
  Solution s;
  cout << s.totalNQueens(8) << endl;
  return 0;
}