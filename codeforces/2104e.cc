#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  cin >> t;

  auto ask = [&](string query, int x) -> int {
    if (query == "digit")
      cout << query << endl;
    else
      cout << query << " " << x << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
  };

  auto answer = [&]() -> int {
    cout << "!" << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
  };

  while (t--) {
    cin >> n;
    ask("mul", 9);
    ask("digit", 0);
    ask("digit", 0);
    ask("add", n - 9);
    answer();
  }
  return 0;
}
