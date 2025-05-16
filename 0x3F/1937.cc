#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  long long maxPoints(vector<vector<int>>& points) {
    int n = points.size(), m = points[0].size();

    vector dp(n, vector(m, -100'000LL));
    vector suf_max(n, vector(m, -100'000LL));
    vector pre_max(n, vector(m, -100'000LL));

    for (int row = 0; row < n; row++) {
      if (row == 0) {
        for (int col = 0; col < m; col++) dp[row][col] = points[row][col];
      } else {
        for (int col = 0; col < m; col++) {
          long long choose_left =
              pre_max[row - 1][col] - col + points[row][col];
          long long choose_right =
              suf_max[row - 1][col] + col + points[row][col];
          dp[row][col] = max(choose_left, choose_right);
        }
      }

      for (int col = 0; col < m; col++) {
        cout << dp[row][col] << " ";
      }
      cout << endl;

      for (int col = 0; col < m; col++) {
        pre_max[row][col] = dp[row][col] + col;
        if (col)
          pre_max[row][col] = max(pre_max[row][col], pre_max[row][col - 1]);
      }
      for (int col = m - 1; col >= 0; col--) {
        suf_max[row][col] = dp[row][col] - col;
        if (col < m - 1)
          suf_max[row][col] = max(suf_max[row][col], suf_max[row][col + 1]);
      }
    }

    return *max_element(dp[n - 1].begin(), dp[n - 1].end());
  }
};

int main() { return 0; }