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
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  int inv_count = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (a[i] > a[j]) inv_count++;
    }
  }
  // cout << n * (n - 1) - inv_count << '\n';
  // make the sequence sorted in non-increasing order
  vector<pair<int, int>> ans;
  for (int cur = n; cur >= 1; cur--) {
    int cur_idx = -1;
    for (int i = 1; i <= n; i++) {
      if (a[i] == cur) {
        cur_idx = i;
        break;
      }
    }
    int target_idx = n - cur + 1;
    for (int i = cur_idx; i > target_idx; i--) {
      ans.push_back({ a[i], a[i - 1] });
      swap(a[i], a[i - 1]);
    }
  }
  // make the sequence sorted in non-decreasing order
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) ans.push_back({ i, j });
  }

  cout << ans.size() << '\n';
  reverse(ans.begin(), ans.end());
  for (auto [x, y] : ans) cout << y << ' ' << x << '\n';
  return 0;
}
