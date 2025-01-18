#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minCost(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> cost(n, vector<int>(m, INT_MAX));
    deque<pair<int, int>> dq;

    // Directions: right, left, down, up
    vector<vector<int>> directions = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

    // Initialize starting point
    dq.push_front({ 0, 0 });
    cost[0][0] = 0;

    while (!dq.empty()) {
      auto [x, y] = dq.front();
      dq.pop_front();

      for (int d = 0; d < 4; ++d) {
        int nx = x + directions[d][0];
        int ny = y + directions[d][1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
          int newCost = cost[x][y] + (grid[x][y] == d + 1 ? 0 : 1);
          if (newCost < cost[nx][ny]) {
            cost[nx][ny] = newCost;
            if (grid[x][y] == d + 1) {
              dq.push_front({ nx, ny }); // Prioritize no-cost moves
            }
            else {
              dq.push_back({ nx, ny });
            }
          }
        }
      }
    }

    return cost[n - 1][m - 1];
  }
};

int main() {
  return 0;
}