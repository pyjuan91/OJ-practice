#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    deque<int> freeze;
    multiset<int> moving_back;
    for (int i = n - 1; i >= 0; i--) {
      if (freeze.empty() or a[i] <= freeze.front()) {
        freeze.push_front(a[i]);
      }
      else {
        moving_back.insert(a[i] + 1);
      }
      // debug(freeze, moving_back);
      while (!freeze.empty() and !moving_back.empty() and freeze.back() > *moving_back.begin()) {
        moving_back.insert(freeze.back() + 1);
        freeze.pop_back();
      }
      // debug(freeze, moving_back);
    }

    // debug(freeze, moving_back);
    for (auto& x : freeze) cout << x << ' ';
    for (auto& x : moving_back) cout << x << ' ';
    cout << '\n';
  }

  return 0;
}
