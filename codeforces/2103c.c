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
  int t, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
      pref[i] = pref[i - 1] + (a[i] <= k);
    }

    vector<bool> good_two(n + 1, false);
    for (int i = 1; i <= n; i++) {
      if (i % 2 == 0) {
        good_two[i] = (2 * pref[i] >= i);
      }
      else {
        good_two[i] = (2 * pref[i] > i);
      }
    }

    vector<bool> suff(n + 2, false);
    for (int i = 1; i <= n; i++) {
      int cnt = pref[n] - pref[i - 1];
      int len = n - i + 1;
      if (len % 2 == 0) {
        suff[i] = (2 * cnt >= len);
      }
      else {
        suff[i] = (2 * cnt > len);
      }
    }

    priority_queue<int, vector<int>, greater<int>> pq_whole[2], pq_pref[2];
    bool pref_good = false;
    bool ok = false;

    for (int r = 2; r <= n - 1; r++) {
      int l = r - 1;
      pq_whole[l % 2].push(2 * pref[l] - l);
      if (good_two[l]) {
        pq_pref[l % 2].push(2 * pref[l] - l);
        pref_good = true;
      }

      int threshold_even = 2 * pref[r] - r;
      int threshold_odd = 2 * pref[r] - r - 1 + (r % 2);

      bool good_one_two = false;
      if (!pq_pref[0].empty() and pq_pref[0].top() <= threshold_even) {
        good_one_two = true;
      }
      if (!pq_pref[1].empty() and pq_pref[1].top() <= threshold_odd) {
        good_one_two = true;
      }
      ok |= good_one_two;
      if (ok) break;

      if (suff[r + 1]) {
        bool good_two_three = false;
        if (!pq_whole[0].empty() and pq_whole[0].top() <= threshold_even) {
          good_two_three = true;
        }
        if (!pq_whole[1].empty() and pq_whole[1].top() <= threshold_odd) {
          good_two_three = true;
        }
        ok |= good_two_three;
        if (ok) break;
      }

      if (pref_good and suff[r + 1]) {
        ok = true;
        break;
      }
    }

    cout << (ok ? "YES" : "NO") << "\n";
  }
  return 0;
}
