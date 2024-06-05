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
    deque<int> a(n);
    for (auto &x : a) cin >> x;

    int res = 0;
    while (a.size() > 1 and k > 0) {
      int mi = min(a.front(), a.back());
      if (k >= 2 * mi) {
        a.front() -= mi, a.back() -= mi;
        k -= 2 * mi;
      } else {
        a.front() -= k / 2 + k % 2;
        a.back() -= k / 2;
        k = 0;
      }

      if (a.front() == 0) a.pop_front(), res++;
      if (a.back() == 0) a.pop_back(), res++;
    }

    if (k > 0 and a.size() == 1 and a.front() <= k) res++;
    cout << res << '\n';
  }
  return 0;
}
