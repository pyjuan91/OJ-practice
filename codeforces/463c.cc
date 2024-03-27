#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cin >> a[i][j];
  }
  vector<int> diag_sum(2 * n - 1), anti_diag_sum(2 * n - 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      diag_sum[i + j] += a[i][j];
      anti_diag_sum[i - j + n - 1] += a[i][j];
    }
  }
  tuple<int, int, int> res_light_bishop = {0, 0, 0};
  tuple<int, int, int> res_dark_bishop = {0, 1, 0};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int cur_sum = diag_sum[i + j] + anti_diag_sum[i - j + n - 1] - a[i][j];
      if ((i + j) % 2 == 0 && cur_sum > get<2>(res_light_bishop)) {
        res_light_bishop = {i, j, cur_sum};
      }
      if ((i + j) % 2 == 1 && cur_sum > get<2>(res_dark_bishop)) {
        res_dark_bishop = {i, j, cur_sum};
      }
    }
  }
  cout << get<2>(res_light_bishop) + get<2>(res_dark_bishop) << '\n';
  cout << get<0>(res_light_bishop) + 1 << ' ' << get<1>(res_light_bishop) + 1
       << ' ';
  cout << get<0>(res_dark_bishop) + 1 << ' ' << get<1>(res_dark_bishop) + 1
       << '\n';
  return 0;
}
