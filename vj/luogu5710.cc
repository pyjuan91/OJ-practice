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
  int attributes = 0;
  if (n % 2 == 0) attributes++;
  if (n > 4 and n <= 12) attributes++;
  cout << (attributes == 2) << " " << (attributes >= 1) << " "
       << (attributes == 1) << " " << (attributes == 0) << "\n";
  return 0;
}
