#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

const int kMax = 5e5 + 5;
int K;
string S, T;

int dp[kMax][45];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> K >> S >> T;
  int n = S.size(), m = T.size();
  if (llabs(n - m) > K) {
    cout << "No\n";
    return 0;
  }
  S = " " + S, T = " " + T;
  for (int j = -K; j < 0; j++) {
    dp[0][j + K + 1] = (INT64_MAX >> 4);
  }
  for (int j = 0; j <= K; j++) {
    dp[0][j + K + 1] = j;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = -K; j <= K; j++) {
      int t_pos = i + j;
      if (t_pos < 1 or t_pos > m) {
        dp[i][j + K + 1] = (INT64_MAX >> 4);
        continue;
      }
      int cost = (S[i] != T[t_pos]);
      dp[i][j + K + 1] = min(
        {
          j == K ? INT32_MAX : dp[i - 1][j + K + 2] + 1,
          j == -K ? INT32_MAX : dp[i][j + K] + 1,
          j == -K ? INT32_MAX : dp[i - 1][j + K + 1] + cost
        }
      );
      debug(i, j, dp[i][j + K + 1]);
    }
  }

  if (dp[n][m - n + K + 1] <= K) {
    cout << "Yes\n";
    return 0;
  }
  cout << "No\n";
  return 0;
}
