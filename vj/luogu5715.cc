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
  array<int, 3> a;
  for (int i = 0; i < 3; i++) cin >> a[i];
  sort(a.begin(), a.end());
  for (int i = 0; i < 3; i++) cout << a[i] << " ";
  return 0;
}
