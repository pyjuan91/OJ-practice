#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, res = 0;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  if (n <= 3) {
    for (auto x : a) res |= x;
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          res = max(res, a[i] | a[j] | a[k]);
        }
      }
    }
  }
  cout << res << '\n';
  return 0;
}
