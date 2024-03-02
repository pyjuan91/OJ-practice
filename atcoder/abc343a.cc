#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int a, b;
  cin >> a >> b;
  int res = a + b;
  if (res == 0)
    res = 9;
  else
    res--;
  cout << res << '\n';
  return 0;
}
