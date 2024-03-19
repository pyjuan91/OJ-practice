#include <bits/stdc++.h>
#define int long long
using namespace std;

int chaewon(int a, int b, int c) {
  int gg = __gcd(a, b);
  int lcm = a / gg * b;
  return c / a + c / b + 2;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, a, b, c;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    cout << chaewon(a, b, c) << "\n";
  }
  return 0;
}
