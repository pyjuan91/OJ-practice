#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n, m, k;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    int res = 0;
    for (auto i : a) {
      for (auto j : b) {
        if (i + j <= k) res++;
      }
    }
    cout << res << '\n';
  }
  return 0;
}
