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
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    auto min = *min_element(a.begin(), a.end());
    auto max = *max_element(a.begin(), a.end());
    cout << max - min << '\n';
  }
  return 0;
}
