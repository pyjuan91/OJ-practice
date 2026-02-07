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
    vector<int> a(n + 1);
    vector<bool> used(n + 1);
    a[n] = 1;
    used[1] = true;
    for (int i = n - 1; i > 1; i--) {
      a[i] = 1 xor i;
      used[a[i]] = true;
    }
    for (int i = 1; i <= n; i++) {
      if (!used[i]) a[1] = i;
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";
  }
  return 0;
}
