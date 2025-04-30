#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> pathsWithMaxScore(vector<string>& board) {
    constexpr int kMod = 1e9 + 7;
    size_t n = board.size();
    board[0][0] = board[n - 1][n - 1] = '0';
    vector dp(n, vector(n, pair<int, int>(-1, 0)));
    dp[n - 1][n - 1] = {0, 1};
    for (int i = n - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        if (!isdigit(board[i][j]) or dp[i][j].first < 0) continue;
        if (i - 1 >= 0 and isdigit(board[i - 1][j])) {
          if (dp[i - 1][j].first < dp[i][j].first + (board[i - 1][j] - '0')) {
            dp[i - 1][j].first = dp[i][j].first + (board[i - 1][j] - '0');
            dp[i - 1][j].second = dp[i][j].second;
          } else if (dp[i - 1][j].first ==
                     dp[i][j].first + (board[i - 1][j] - '0')) {
            dp[i - 1][j].second =
                (dp[i - 1][j].second + dp[i][j].second) % kMod;
          }
        }
        if (j - 1 >= 0 and isdigit(board[i][j - 1])) {
          if (dp[i][j - 1].first < dp[i][j].first + (board[i][j - 1] - '0')) {
            dp[i][j - 1].first = dp[i][j].first + (board[i][j - 1] - '0');
            dp[i][j - 1].second = dp[i][j].second;
          } else if (dp[i][j - 1].first ==
                     dp[i][j].first + (board[i][j - 1] - '0')) {
            dp[i][j - 1].second =
                (dp[i][j - 1].second + dp[i][j].second) % kMod;
          }
        }
        if (i - 1 >= 0 and j - 1 >= 0 and isdigit(board[i - 1][j - 1])) {
          if (dp[i - 1][j - 1].first <
              dp[i][j].first + (board[i - 1][j - 1] - '0')) {
            dp[i - 1][j - 1].first =
                dp[i][j].first + (board[i - 1][j - 1] - '0');
            dp[i - 1][j - 1].second = dp[i][j].second;
          } else if (dp[i - 1][j - 1].first ==
                     dp[i][j].first + (board[i - 1][j - 1] - '0')) {
            dp[i - 1][j - 1].second =
                (dp[i - 1][j - 1].second + dp[i][j].second) % kMod;
          }
        }
      }
    }
    if (dp[0][0].first < 0) return {0, 0};
    return {dp[0][0].first, dp[0][0].second};
  }
};

int main() { return 0; }