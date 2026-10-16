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
  int n, x, sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (i % 2 == 0) sum += x;
  }
  cout << sum << "\n";
  return 0;
}
