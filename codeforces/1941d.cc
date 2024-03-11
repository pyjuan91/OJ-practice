#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n, m, k;
  char c;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    vector<bool> a(n, false);
    a[k - 1] = true;
    while (m--) {
      cin >> k >> c;
      vector<bool> b(n, false);
      for (int i = 0; i < n; i++) {
        if (a[i]) {
          if (c == '0') {
            b[(i + k) % n] = true;
          }
          if (c == '1') {
            b[(i + n - k) % n] = true;
          }
          if (c == '?') {
            b[(i + k) % n] = true;
            b[(i + n - k) % n] = true;
          }
        }
      }
      swap(a, b);
    }
    vector<int> res;
    for (int i = 0; i < n; i++) {
      if (a[i]) {
        res.push_back(i);
      }
    }
    cout << res.size() << "\n";
    for (auto i : res) {
      cout << i + 1 << " ";
    }
    cout << "\n";
  }
  return 0;
}
