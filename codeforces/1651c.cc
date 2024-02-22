#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    auto cost = [&](int i, int j) { return llabs(a[i] - b[j]); };
    int up_left, up_right, down_left, down_right;
    up_left = up_right = down_left = down_right = INT64_MAX;
    for (int i = 0; i < n; i++) {
      up_left = min(up_left, cost(0, i));
      up_right = min(up_right, cost(n - 1, i));
      down_left = min(down_left, cost(i, 0));
      down_right = min(down_right, cost(i, n - 1));
    }
    int res = up_left + up_right + down_left + down_right;
    res = min(res, cost(0, 0) + up_right + down_right);
    res = min(res, cost(0, n - 1) + up_right + down_left);
    res = min(res, cost(n - 1, 0) + up_left + down_right);
    res = min(res, cost(n - 1, n - 1) + up_left + down_left);
    res = min(res, cost(0, 0) + cost(n - 1, n - 1));
    res = min(res, cost(0, n - 1) + cost(n - 1, 0));
    cout << res << '\n';
  }
  return 0;
}
