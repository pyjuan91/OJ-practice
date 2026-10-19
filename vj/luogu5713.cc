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
  if (n * 5 < n * 3 + 11)
    cout << "Local\n";
  else
    cout << "Luogu\n";
  return 0;
}
