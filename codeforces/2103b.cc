#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  string s;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    int cnt_one_zero = 0, cnt_zero_one = 0;
    bool suffix_good = false;
    char last = s[n - 1];
    for (int i = 0; i + 1 < n; i++) {
      if (s[i] != s[i + 1]) {
        if (s[i] == '0') cnt_zero_one++;
        else cnt_one_zero++;
        if (last == s[i])
          suffix_good = true;
      }
    }
    int cnt = cnt_zero_one + cnt_one_zero;
    int base = n + cnt + (s[0] == '1');
    bool good = (cnt_zero_one >= 2)
      || (cnt_one_zero >= 2)
      || (s[0] == '1' && cnt_zero_one >= 1);
    if (good) {
      cout << (base - 2) << "\n";
      continue;
    }
    bool use_one = (s[0] == '1' and last == '0') or suffix_good;
    cout << (base - (use_one ? 1 : 0)) << "\n";
  }
  return 0;
}
