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
    set<int> s;
    int x;
    for (int i = 0; i < n; i++) {
      cin >> x;
      s.insert(x);
    }
    cout << s.size() << '\n';
  }
  return 0;
}
