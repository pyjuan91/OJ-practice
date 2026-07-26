#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int shortestBridge(vector<vector<int>>& grid) {
    const size_t n = grid.size();
    const array<int, 4> dx = {-1, 1, 0, 0};
    const array<int, 4> dy = {0, 0, -1, 1};
    queue<pair<int, int>> q_start;
    vector<vector<int>> visited_start;
    bool island_found = false;
    for (size_t i = 0; i < n and not island_found; i++) {
      for (size_t j = 0; j < n and not island_found; j++) {
        if (grid[i][j] == 1) {
          // BFS
          queue<pair<int, int>> q;
          q.push(make_pair(i, j));
          q_start.push(make_pair(i, j));
          vector visited(n, vector<int>(n, -1));
          visited[i][j] = 0;
          while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (size_t k = 0; k < 4; k++) {
              int nx = x + dx[k];
              int ny = y + dy[k];
              if (nx >= 0 and nx < n and ny >= 0 and ny < n and
                      grid[nx][ny] == 1 and visited[nx][ny] == -1) {
                visited[nx][ny] = 0;
                q.push(make_pair(nx, ny));
                q_start.push(make_pair(nx, ny));
              }
            }
          }
          visited_start = visited;
          island_found = true;
        }
      }
    }

    while (!q_start.empty()) {
      auto [x, y] = q_start.front();
      q_start.pop();
      for (size_t i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 and nx < n and ny >= 0 and ny < n and
            visited_start[nx][ny] == -1) {
          visited_start[nx][ny] = visited_start[x][y] + 1;
          if (grid[nx][ny] == 1) return visited_start[nx][ny] - 1;
          q_start.push(make_pair(nx, ny));
        }
      }
    }

    return -1;
  }
};

int main() { return 0; }