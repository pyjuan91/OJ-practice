#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    auto finished = [&]() {
      int blocks = 0;
      for (int i = 0; i < n; i++) {
        if (a[i]) {
          while (i < n && a[i]) i++;
          blocks++;
          i--;
        }
      }
      return blocks <= 1;
    };
    auto right_most = [&]() {
      for (int i = n - 1; i >= 0; i--) {
        if (a[i]) return i;
      }
      return -1ll;
    };
    auto left_free = [&](int x) {
      for (int i = x - 1; i >= 0; i--) {
        if (a[i] == 0) return i;
      }
      return -1ll;
    };
    int res = 0;
    for (;;) {
      if (finished()) break;
      int right = right_most();
      int left = left_free(right);
      swap(a[left], a[right]);
      res++;
    }
    cout << res << '\n';
  }
  return 0;
}
