#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

const int kMax = 1e6 + 5, kBlockSize = sqrt(kMax);
int n, m, l, r, k, a[kMax], cnt[kMax << 1], pref[kMax], res[kMax];

struct Query {
  int l, r, id;
  Query() {}
  Query(int l, int r, int id) : l(l), r(r), id(id) {}
} queries[kMax];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1] ^ a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> l >> r;
    queries[i] = Query(l - 1, r, i);
  }

  sort(queries + 1, queries + m + 1, [&](Query a, Query b) {
    if (a.l / kBlockSize != b.l / kBlockSize)
      return a.l / kBlockSize < b.l / kBlockSize;
    return a.r < b.r;
  });

  int ans = 0, l = 1, r = 0;
  for (int i = 1; i <= m; i++) {
    while (l < queries[i].l) {
      cnt[pref[l]]--;
      ans -= cnt[pref[l] ^ k];
      l++;
      // debug(l, r, ans);
    }
    while (l > queries[i].l) {
      l--;
      ans += cnt[pref[l] ^ k];
      cnt[pref[l]]++;
      // debug(l, r, ans);
    }
    while (r < queries[i].r) {
      r++;
      ans += cnt[pref[r] ^ k];
      cnt[pref[r]]++;
      // debug(l, r, ans);
    }
    while (r > queries[i].r) {
      cnt[pref[r]]--;
      ans -= cnt[pref[r] ^ k];
      r--;
      // debug(l, r, ans);
    }
    // debugArr(cnt, 10);
    // debug(i, l, r, ans);

    res[queries[i].id] = ans;
  }
  for (int i = 1; i <= m; i++) {
    cout << res[i] << "\n";
  }
  return 0;
}