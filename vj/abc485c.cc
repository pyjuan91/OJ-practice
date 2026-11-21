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
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  vector<int> res(n, INT32_MAX);

  pair<int, int> left1 = make_pair(a[0], 0);
  pair<int, int> left2 = make_pair(INT32_MIN, INT32_MIN);
  for (int i = 1; i < n; i++) {
    if (a[i] != left1.first) {
      res[i] = min(res[i], i - left1.second);
      left2 = left1;
      left1 = make_pair(a[i], i);
    } else {
      left1.second = i;
      res[i] = min(res[i], i - left2.second);
    }
  }
  // debug(res);

  pair<int, int> right1 = make_pair(a[n - 1], n - 1);
  pair<int, int> right2 = make_pair(INT32_MAX, INT32_MAX);
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] != right1.first) {
      res[i] = min(res[i], right1.second - i);
      right2 = right1;
      right1 = make_pair(a[i], i);
    } else {
      right1.second = i;
      res[i] = min(res[i], right2.second - i);
    }
  }

  for (const auto& x : res) cout << x << " ";
  return 0;
}
