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
  while (t--) {
    cin >> n;
    auto ask = [](string s) {
      cout << "1 " << s << endl;
      cout.flush();
      int x;
      cin >> x;
      return x;
      };
    auto answer = [&](int x) {
      cout << "0 " << n << " " << x << endl;
      cout.flush();
      int y;
      cin >> y;
      assert(y == 1);
      };
    int ones = ask("1");
    if (ones == 0) {
      answer(0);
      continue;
    }
    if (ones == n) {
      answer(1);
      continue;
    }
    int one_one = ask("11");
    int segs = ones - one_one;
    int one_zero = ask("10");
    if (one_zero == segs) {
      answer(0);
    }
    else {
      answer(1);
    }
  }
  return 0;
}
