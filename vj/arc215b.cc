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
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(2 * n);
    for (auto& x : a) cin >> x;
    vector<int> res;
    vector<int> state(n + 1, 0);
    // state 0: haven't visited
    // state 1: ignored by even
    // state 2: visited by one
    bool odd = true;
    for (int i = 0; i < 2 * n; i++) {
      if (odd) {
        if (state[a[i]] == 0 or state[a[i]] == 1) {
          state[a[i]] = 2;
        } else if (state[a[i]] == 2) {
          odd = false;
          res.push_back(i);
        }
      } else {
        if (state[a[i]] == 0) {
          state[a[i]] = 1;
        } else if (state[a[i]] == 1) {
          odd = true;
          res.push_back(i);
          state[a[i]] = 2;
        }
      }
    }
    cout << res.size() << "\n";
    for (const auto& x : res) cout << x << " ";
    cout << "\n";
  }

  return 0;
}
