#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, kase = 1;
  while (cin >> n && n) {
    cout << "Case " << kase++ << ": maximum height = ";
    vector<array<int, 3>> a(3 * n);
    int ma_x = 0, ma_y = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[3 * i][0] >> a[3 * i][1] >> a[3 * i][2];
      sort(a[3 * i].begin(), a[3 * i].end());
      a[3 * i + 1] = {a[3 * i][1], a[3 * i][2], a[3 * i][0]};
      a[3 * i + 2] = {a[3 * i][0], a[3 * i][2], a[3 * i][1]};
      ma_x = max({ma_x, a[3 * i][0], a[3 * i][1]});
      ma_y = max({ma_y, a[3 * i][1], a[3 * i][2]});
    }
    int res = 0;
    sort(a.begin(), a.end(), [](array<int, 3> x, array<int, 3> y) {
      return x[0] < y[0] || (x[0] == y[0] && x[1] < y[1]);
    });
    vector<int> dp(3 * n);
    dp[0] = a[0][2];
    for (int i = 1; i < 3 * n; i++) {
      dp[i] = a[i][2];
      for (int j = 0; j < i; j++) {
        if (a[j][0] < a[i][0] && a[j][1] < a[i][1]) {
          dp[i] = max(dp[i], dp[j] + a[i][2]);
        }
      }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
  }
  return 0;
}
