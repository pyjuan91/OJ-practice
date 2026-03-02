#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minSwaps(vector<vector<int>>& grid) {
    const int n = grid.size();
    int res = 0;
    for (int row = 0; row < n; row++) {
      int cnt = 0;
      for (int col = n - 1; col >= 0 && grid[row][col] == 0; col--) cnt++;
      if (cnt >= n - 1 - row) continue;
      bool ok = false;
      for (int sr = row + 1; sr < n; sr++) {
        int cnt = 0;
        for (int col = n - 1; col >= 0 && grid[sr][col] == 0; col--) cnt++;
        if (cnt >= n - 1 - row) {
          for (; sr > row; sr--) {
            swap(grid[sr - 1], grid[sr]);
            res++;
          }
          ok = true;
          break;
        }
      }
      if (!ok) return -1;
    }

    return res;
  }
};

int main() { return 0; }