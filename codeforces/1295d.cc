#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, a, b;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    int n = b / gcd(a, b);
    int ans = n;
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        ans = ans / i * (i - 1);
        while (n % i == 0) n /= i;
      }
    }
    if (n > 1) ans = ans / n * (n - 1);
    cout << ans << '\n';
  }
  return 0;
}
