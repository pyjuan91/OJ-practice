#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int n = dungeon.size(), m = dungeon[0].size();
    set<pair<int, int>> dp[n][m];

    auto optimal_insert = [&](set<pair<int, int>>& s, pair<int, int> p) {
      auto it = s.lower_bound(p);
      while (it != s.begin()) {
        it--;
        if (it->second <= p.second) {
          it = s.erase(it);
        } else {
          continue;
        }
      }
      s.insert(p);
    };

    for (int i = 0; i < n; i++) {
      if (i == 0) {
        dp[i][0].insert({dungeon[i][0], dungeon[i][0]});
        for (int j = 1; j < m; j++) {
          for (auto& prev : dp[i][j - 1]) {
            // dp[i][j].insert({prev.first + dungeon[i][j],
            //                  min(prev.second, prev.first + dungeon[i][j])});
            optimal_insert(dp[i][j],
                           {prev.first + dungeon[i][j],
                            min(prev.second, prev.first + dungeon[i][j])});
          }
        }
      } else {
        for (int j = 0; j < m; j++) {
          for (auto& prev : dp[i - 1][j]) {
            // dp[i][j].insert({prev.first + dungeon[i][j],
            //                  min(prev.second, prev.first + dungeon[i][j])});
            optimal_insert(dp[i][j],
                           {prev.first + dungeon[i][j],
                            min(prev.second, prev.first + dungeon[i][j])});
          }
          if (j > 0) {
            for (auto& prev : dp[i][j - 1]) {
              // dp[i][j].insert({prev.first + dungeon[i][j],
              //                  min(prev.second, prev.first +
              //                  dungeon[i][j])});
              optimal_insert(dp[i][j],
                             {prev.first + dungeon[i][j],
                              min(prev.second, prev.first + dungeon[i][j])});
            }
          }
        }
      }
    }
    // print dp
    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < m; j++) {
    //     cout << i << " " << j << ": ";
    //     for (auto& p : dp[i][j]) {
    //       cout << "(" << p.first << ", " << p.second << ") ";
    //     }
    //     cout << endl;
    //   }
    // }
    int res = INT32_MAX;
    for (auto& p : dp[n - 1][m - 1]) {
      res = min(res, -p.second + 1);
    }
    return max(res, 1);
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> dungeon(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> dungeon[i][j];
    }
  }
  Solution solution;
  cout << solution.calculateMinimumHP(dungeon) << endl;
  return 0;
}
