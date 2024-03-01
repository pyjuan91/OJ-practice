#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  string s1, s2;
  cin >> t;
  while (t--) {
    cin >> n >> s1 >> s2;
    s1 = " " + s1, s2 = " " + s2;
    int first_10 = n + 1;
    for (int i = 2; i <= n; i++) {
      if (s1[i] == '1' && s2[i - 1] == '0') {
        first_10 = i;
        break;
      }
    }
    string res_str = "";
    int res_cnt = 0;
    if (first_10 == n + 1) {
      res_str = s1;
      res_str += s2[n];
      for (int i = n; i >= 2; i--) {
        if (s1[i] == s2[i - 1])
          res_cnt++;
        else
          break;
      }
    } else {
      for (int i = 1; i < first_10; i++) res_str += s1[i];
      for (int i = first_10 - 1; i <= n; i++) res_str += s2[i];
      for (int i = first_10 - 1; i >= 2; i--) {
        if (s1[i] == s2[i - 1])
          res_cnt++;
        else
          break;
      }
    }
    cout << res_str << '\n';
    cout << res_cnt + 1 << '\n';
  }
  return 0;
}
