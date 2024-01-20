#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string board[2];
  cin >> board[0] >> board[1];
  int n = board[0].size();
  vector<vector<int>> dp(n + 5, vector<int>(16, 0));

  auto get_type = [&](int col) {
    int res = 0;
    if (board[0][col - 1] == 'X') res += (1 << 3);
    if (board[0][col] == 'X') res += (1 << 2);
    if (board[1][col - 1] == 'X') res += (1 << 1);
    if (board[1][col] == 'X') res += 1;
    return res;
  };

  auto test_14 = [&](int t) { return t == 1 || t == 0; };
  auto test_13 = [&](int t) { return t == 2 || t == 0; };
  auto test_7 = [&](int t) { return t == 8 || t == 0; };
  auto test_11 = [&](int t) { return t == 4 || t == 0; };

  for (int i = 1; i < n; i++) {
    int t = get_type(i);
    int pre1 = *max_element(dp[i - 1].begin(), dp[i - 1].end());
    for (int j = 0; j < 16; j++) dp[i][j] = pre1;
    int pre2 = i > 1 ? *max_element(dp[i - 2].begin(), dp[i - 2].end()) : 0;
    if (test_14(t)) dp[i][t + 14] = max(dp[i][t + 14], pre2 + 1);
    if (test_13(t)) dp[i][t + 13] = max(dp[i][t + 13], pre2 + 1);
    if (test_7(t)) dp[i][t + 7] = max(dp[i][t + 7], pre2 + 1);
    if (test_11(t)) dp[i][t + 11] = max(dp[i][t + 11], pre2 + 1);
    if (test_13(t)) {
      for (int j = 0; j < 16; j++) {
        if ((j & 4) == 0 && (j & 1) == 1)
          dp[i][15] = max(dp[i][15], dp[i - 1][j] + 1);
        if (j & 4 == 0 && j & 1 == 0)
          dp[i][13] = max(dp[i][13], dp[i - 1][j] + 1);
      }
    }
    if (test_7(t)) {
      for (int j = 0; j < 16; j++) {
        if ((j & 4) == 1 && (j & 1) == 0)
          dp[i][15] = max(dp[i][15], dp[i - 1][j] + 1);
        if ((j & 4) == 0 && (j & 1) == 0)
          dp[i][7] = max(dp[i][7], dp[i - 1][j] + 1);
      }
    }
    // cout << t << endl;
    // for(int j=0;j<16;j++) {
    //     cout << dp[i][j] << " ";
    // }
    // cout << endl;
  }

  cout << *max_element(dp[n - 1].begin(), dp[n - 1].end());
  return 0;
}
