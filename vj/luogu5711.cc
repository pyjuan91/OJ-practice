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
  int n;
  cin >> n;
  if ((n % 4 == 0 and n % 100 != 0) or (n % 400 == 0))
    cout << "1\n";
  else
    cout << "0\n";
  return 0;
}
