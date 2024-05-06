#include <bits/stdc++.h>
using namespace std;

const int kMax = 5005;
int t, n, a[kMax], b[kMax];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a, a + n), sort(b, b + n);

    int res = 0;
    for (int start_j = 0; start_j < n; start_j++) {
      int mi = INT32_MAX;
      for (int i = 0; i < n; i++) {
        int j = (i + start_j) % n;
        mi = min(mi, abs(a[i] - b[j]));
      }
      res = max(res, mi);
    }
    cout << res << '\n';
  }

  return 0;
}
