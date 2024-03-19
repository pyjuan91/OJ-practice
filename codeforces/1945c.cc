#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  string s;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    s = " " + s;
    vector<int> pre_zero(n + 1);
    for (int i = 1; i <= n; i++) {
      pre_zero[i] = pre_zero[i - 1] + (s[i] == '0');
    }
    int res = n + 1;
    for (int i = 0; i <= n; i++) {
      int left_zeros = pre_zero[i];
      int right_ones = n - i - (pre_zero[n] - pre_zero[i]);
      bool ok = (left_zeros >= (i + 1) / 2) && (right_ones >= (n - i + 1) / 2);
      if (ok && (llabs(n - 2 * i) < llabs(n - 2 * res))) {
        res = i;
      }
    }
    cout << res << "\n";
  }
  return 0;
}
