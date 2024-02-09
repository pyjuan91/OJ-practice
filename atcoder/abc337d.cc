#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> a(n);
  for (auto &s : a) cin >> s;
  int res = INT32_MAX;
  if (k <= m) {
    for (int i = 0; i < n; i++) {
      int cross_cnt = 0, dot_cnt = 0;
      for (int j = 0; j < k; j++) {
        if (a[i][j] == 'x') cross_cnt++;
        if (a[i][j] == '.') dot_cnt++;
      }
      if (cross_cnt == 0) res = min(res, dot_cnt);
      for (int j = k; j < m; j++) {
        if (a[i][j - k] == 'x') cross_cnt--;
        if (a[i][j - k] == '.') dot_cnt--;
        if (a[i][j] == 'x') cross_cnt++;
        if (a[i][j] == '.') dot_cnt++;
        if (cross_cnt == 0) res = min(res, dot_cnt);
      }
    }
  }
  if (k <= n) {
    for (int i = 0; i < m; i++) {
      int cross_cnt = 0, dot_cnt = 0;
      for (int j = 0; j < k; j++) {
        if (a[j][i] == 'x') cross_cnt++;
        if (a[j][i] == '.') dot_cnt++;
      }
      if (cross_cnt == 0) res = min(res, dot_cnt);
      for (int j = k; j < n; j++) {
        if (a[j - k][i] == 'x') cross_cnt--;
        if (a[j - k][i] == '.') dot_cnt--;
        if (a[j][i] == 'x') cross_cnt++;
        if (a[j][i] == '.') dot_cnt++;
        if (cross_cnt == 0) res = min(res, dot_cnt);
      }
    }
  }
  cout << (res == INT32_MAX ? -1 : res) << '\n';
  return 0;
}
