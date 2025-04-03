#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minTimeToReach(vector<vector<int>>& moveTime) {
    int n = moveTime.size();
    int m = moveTime[0].size();
    vector<vector<int>> dp(n, vector<int>(m, INT32_MAX));
    dp[0][0] = 0;
    auto cmp = [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
      return get<2>(a) > get<2>(b);
      };
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> pq(cmp);
    pq.push({ 0, 0, 0 });
    while (!pq.empty()) {
      auto [x, y, t] = pq.top();
      pq.pop();
      if (x == n - 1 and y == m - 1) return t;
      if (t > dp[x][y]) continue;

      const array<int, 4> dx = { 0, 0, -1, 1 };
      const array<int, 4> dy = { -1, 1, 0, 0 };
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        int nt = max(t + 1, moveTime[nx][ny] + 1);
        if (nt < dp[nx][ny]) {
          dp[nx][ny] = nt;
          pq.push({ nx, ny, nt });
        }
      }
    }
    return -1;
  }
};

int main() { return 0; }