#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n + 2);
    bool all_same = true;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] != a[1]) all_same = false;
    }
    if (all_same) {
      cout << "-1\n";
      continue;
    }
    if (a[1] != a[n]) {
      cout << "0\n";
      continue;
    }
    int res = n - 1, prev_diff_pos = 0;
    for (int i = 2; i <= n - 1; i++) {
      if (a[i] != a[1] && a[i + 1] != a[1]) {
        cout << "0\n";
        goto end;
      }
      if (a[i] != a[1]) {
        res = min(res, i - prev_diff_pos - 1);
        prev_diff_pos = i;
      }
    }
    prev_diff_pos = n + 1;
    for (int i = n - 1; i >= 2; i--) {
      if (a[i] != a[n] && a[i - 1] != a[n]) {
        cout << "0\n";
        goto end;
      }
      if (a[i] != a[n]) {
        res = min(res, prev_diff_pos - i - 1);
        prev_diff_pos = i;
      }
    }
    cout << res << '\n';

  end:;
  }
  return 0;
}
