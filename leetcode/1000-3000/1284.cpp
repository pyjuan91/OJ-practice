#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minFlips(vector<vector<int>>& mat) {
    map<vector<vector<int>>, int> dp;
    queue<vector<vector<int>>> q;
    int n = mat.size(), m = mat[0].size();
    auto check = [&](vector<vector<int>>& mat) {
      for (auto& i : mat) {
        for (auto& j : i)
          if (j) return false;
      }
      return true;
    };

    auto flip = [&](auto& mat, int x, int y) {
      vector<vector<int>> neo = mat;
      neo[x][y] = !neo[x][y];
      if (x > 0) neo[x - 1][y] = !neo[x - 1][y];
      if (x < n - 1) neo[x + 1][y] = !neo[x + 1][y];
      if (y > 0) neo[x][y - 1] = !neo[x][y - 1];
      if (y < m - 1) neo[x][y + 1] = !neo[x][y + 1];
      return neo;
    };

    q.push(mat);
    dp[mat] = 0;
    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      int step = dp[cur];
      if (check(cur)) return step;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          auto neo = flip(cur, i, j);
          if (!dp.count(neo)) {
            dp[neo] = step + 1;
            q.push(neo);
          }
        }
      }
    }
    return -1;
  }
};
int main() {
  Solution s;
  int n, m;
  cin >> n >> m;
  vector<vector<int>> mat(n, vector<int>(m));
  for (auto& i : mat) {
    for (auto& j : i) {
      cin >> j;
    }
  }
  cout << s.minFlips(mat) << endl;
  return 0;
}