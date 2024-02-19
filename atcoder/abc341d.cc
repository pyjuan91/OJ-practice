#include <bits/stdc++.h>
#define int long long
using namespace std;

int woogie(int n, int m, int k) {
  int l = 0, r = INT64_MAX, mid, w, block = n * m / __gcd(n, m);
  while (l + 1 < r) {
    mid = (l + r) / 2;
    w = mid / n + mid / m - 2 * (mid / block);
    if (w < k)
      l = mid;
    else
      r = mid;
  }
  return r;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  cout << woogie(n, m, k) << '\n';
  return 0;
}
