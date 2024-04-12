#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n, m, k;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    if (m == 1 || n == 1 || k >= n - 1) {
      cout << "NO\n";
      continue;
    }
    if (m == 2) {
      if (k >= n / 2) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
      }
      continue;
    }
    int mo = n / m + (n % m != 0);
    if (k >= n - mo) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}
