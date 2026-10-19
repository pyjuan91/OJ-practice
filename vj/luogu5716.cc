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
  int y, m;
  cin >> y >> m;
  const array<int, 7> long_months = {1, 3, 5, 7, 8, 10, 12};
  if (find(long_months.begin(), long_months.end(), m) != long_months.end())
    cout << "31\n";
  else {
    if (m != 2) {
      cout << "30\n";
    } else {
      if ((y % 4 == 0 and y % 100 != 0) or y % 400 == 0)
        cout << "29\n";
      else
        cout << "28\n";
    }
  }
  return 0;
}
