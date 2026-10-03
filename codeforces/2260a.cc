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
    vector<int> a(n);
    int cnt[2] = {};
    for (auto& x : a) {
      cin >> x;
      cnt[x]++;
    }
    if (cnt[0] < 2) {
      cout << "-1\n";
      continue;
    }
    int required = (a.front() == 1) + (a.back() == 1);
    cout << required << "\n";
  }
  return 0;
}
