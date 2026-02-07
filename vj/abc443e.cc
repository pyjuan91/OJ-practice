#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

void patty(int n, int c, vector<string>& a) {
  vector reachable(n, vector(n, false));
  vector low_wall(n, 0LL);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == '#') low_wall[j] = i;
    }
  }
  // debug(low_wall);
  for (int i = 0; i < n; i++) reachable[i][c] = true;
  for (int i = n - 2; i >= 0; i--) {
    for (int j = 0; j < n; j++) {
      if (reachable[i][j]) continue;
      for (int k = max(j - 1, 0LL); k <= min(j + 1, n - 1); k++) {
        reachable[i][j] = reachable[i][j] or reachable[i + 1][k];
      }
      if (reachable[i][j] and a[i][j] == '#') {
        if (low_wall[j] == i) {
          for (int r = 0; r <= i; r++) reachable[r][j] = true;
        } else {
          reachable[i][j] = false;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << (reachable[0][i] ? 1 : 0);
  }
  cout << "\n";
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n, c;
  cin >> t;
  while (t--) {
    cin >> n >> c;
    vector<string> a(n);
    for (auto& s : a) cin >> s;
    patty(n, c - 1, a);
  }
  return 0;
}
