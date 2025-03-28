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
  int t, n, x;
  cin >> t;
  while (t--) {
    cin >> n;
    map<int, int> cnt;
    bool found = false;
    for (int i = 0; i < n; i++) {
      cin >> x;
      cnt[x]++;
      if (!found and cnt[0] >= 3 and cnt[1] >= 1 and cnt[2] >= 2 and cnt[3] >= 1 and cnt[5] >= 1) {
        cout << i + 1 << "\n";
        found = true;
      }
    }
    if (!found) cout << "0\n";
  }
  return 0;
}
