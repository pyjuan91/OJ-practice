#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

string chaewon(int n) {
  if (n % 2 == 1) return "NO";
  for (int i = 2; i <= sqrt(n + 1); i++) {
    if ((n + 1) % i == 0) return "NO";
  }
  return "YES";
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << chaewon(n) << "\n";
  }
  return 0;
}
