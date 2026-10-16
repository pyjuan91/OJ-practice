#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, res = 0;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'R') {
      int j = i;
      for (; j < n and s[j] == 'R'; j++) {
      }
      res = max(res, j - i);
    }
  }
  cout << res << "\n";
  return 0;
}
