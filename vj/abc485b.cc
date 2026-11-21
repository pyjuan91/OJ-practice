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
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (auto& x : s) cin >> x;
  for (int i = 0; i < n; i++) {
    bool clogged = true;
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'o') clogged = false;
    }
    if (clogged) {
      cout << "Faucet " << i + 1;
      return 0;
    }
  }
  for (int i = 0; i < m; i++) {
    bool clogged = true;
    for (int j = 0; j < n; j++) {
      if (s[j][i] == 'o') clogged = false;
    }
    if (clogged) {
      cout << "Drain " << i + 1;
      return 0;
    }
  }
  return 0;
}
