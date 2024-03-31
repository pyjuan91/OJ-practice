#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMax = 2e5 + 5;
int n, a[kMax];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  n = unique(a + 1, a + n + 1) - a - 1;
  int res = 0;
  for (int i = n - 1; i > 0 && a[i] > res; i--) {
    for (int j = 2 * a[i]; j <= a[n] + a[i]; j += a[i]) {
      int ideal_big = lower_bound(a + i + 1, a + n + 1, j) - a - 1;
      res = max(res, a[ideal_big] % a[i]);
    }
  }
  cout << res << '\n';
  return 0;
}
