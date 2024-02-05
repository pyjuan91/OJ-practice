#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  int n = s.size();
  s = " " + s;
  vector<int> dp(n + 1, 0);
  if (n < 2) {
    cout << "0 1\n";
    return 0;
  }
  for (int i = 2; i <= n; i++) {
    if (s[i] == ')') {
      if (s[i - 1] == ')') {
        int left_pos = i - dp[i - 1] - 1;
        if (left_pos >= 1 && s[left_pos] == '(') {
          dp[i] = dp[i - 1] + 2 + dp[left_pos - 1];
        }
      } else {
        dp[i] = dp[i - 2] + 2;
      }
    }
  }
  int max_len = *max_element(dp.begin(), dp.end());
  if (max_len == 0) {
    cout << "0 1\n";
    return 0;
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (dp[i] == max_len) {
      cnt++;
    } else if (dp[i] > max_len) {
      int diff = dp[i] - max_len;
      if (dp[i - max_len - 1] == diff) {
        cnt++;
      }
    }
  }
  cout << max_len << " " << cnt << "\n";
  return 0;
}
