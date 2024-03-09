#include <bits/stdc++.h>
#define int long long
using namespace std;

string s;
int n, a, dp[105], dp_tmp[105];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> s >> n;
  int len = s.size();
  s = " " + s;

  for (int i = 1; i < 105; i++) dp[i] = 1e9, dp_tmp[i] = 1e9;
  dp[0] = dp_tmp[0] = 0;

  for (int i = 1; i <= n; i++) {
    cin >> a;
    for (int j = 1; j <= a; j++) {
      string t;
      cin >> t;
      int len2 = t.size();
      // cout << t << " " << len2 << '\n';
      for (int k = 0; k <= len; k++) {
        if (k + len2 > len) break;
        if (s.substr(k + 1, len2) == t) {
          dp_tmp[k + len2] = min({dp[k] + 1, dp[k + len2], dp_tmp[k + len2]});
          // ::cout << k << " " << k + len2 << " " << dp_tmp[k + len2] << '\n';
        }
      }
    }
    for (int j = 0; j <= len; j++) dp[j] = min(dp[j], dp_tmp[j]);
  }

  cout << (dp[len] >= 1e9 ? -1 : dp[len]) << '\n';
  return 0;
}
