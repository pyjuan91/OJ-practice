#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  for (int i = 0; i < n; i++) a.push_back(a[i]);
  n *= 2;

  auto arith = [&](int x) { return x * (x + 1) / 2; };
  int ans = 0, cur_hug = 0, l_month = 0, l_day = 0, r_month = 0, cur_day = 0;
  for (; r_month < n; r_month++) {
    cur_hug += arith(a[r_month]);
    cur_day += a[r_month];
    // cout << "cur_day: " << cur_day << '\n';
    // cout << "cur_hug: " << cur_hug << '\n';
    if (cur_day > m) {
      while (cur_day > m) {
        int l_shrink = a[l_month] - l_day;
        if (cur_day - l_shrink >= m) {
          cur_day -= l_shrink;
          cur_hug -= (arith(a[l_month]) - arith(l_day));
          l_month++;
          l_day = 0;
          continue;
        }
        // cout << "here\n";
        int extra_days = cur_day - m;
        int new_l_day = l_day + extra_days;
        // cout << new_l_day << '\n';
        // cout << cur_hug << "\n";
        cur_day = m;
        cur_hug -= arith(new_l_day) - arith(l_day);
        l_day = new_l_day;
      }
    }
    // cout << a[r_month] << ' ' << cur_day << ' ' << cur_hug << '\n';
    ans = max(ans, cur_hug);
    // cout << l_month << ' ' << l_day << ' ' << r_month << ' ' << cur_day << ' ' << cur_hug << '\n';
  }
  cout << ans << '\n';
  return 0;
}
