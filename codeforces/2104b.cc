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
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<int> pre_max(n + 2), suf_max(n + 2);
    vector<int> pre_min(n + 2, INT32_MAX), suf_min(n + 2, INT32_MAX);
    vector<int> pre_sum(n + 2), suf_sum(n + 2);
    for (int i = 1; i <= n; i++) {
      pre_max[i] = max(pre_max[i - 1], a[i]);
      pre_sum[i] = pre_sum[i - 1] + a[i];
      pre_min[i] = min(pre_min[i - 1], a[i]);
    }
    for (int i = n; i >= 1; i--) {
      suf_max[i] = max(suf_max[i + 1], a[i]);
      suf_sum[i] = suf_sum[i + 1] + a[i];
      suf_min[i] = min(suf_min[i + 1], a[i]);
    }

    for (int i = 1; i <= n; i++) {
      int didnt_change = suf_sum[n - i + 1];
      int changed = suf_sum[n - i + 2] + pre_max[n - i];
      cout << max(didnt_change, changed) << " ";
    }
    cout << "\n";
  }
  return 0;
}
