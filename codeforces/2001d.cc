#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
using namespace std;
int32_t main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    auto ask = [&](int a, int b) -> int {
      cout << "? " << a << ' ' << b << endl;
      cout.flush();
      int x;
      cin >> x;
      return x;
      };

    vector<pair<int, int>> res;
    vector<bool> in_tree(n + 1, false);
    in_tree[1] = true;

    for (int i = 2; i <= n; i++) {
      int a = 1, b = 1;
      while (in_tree[b]) b++;
      for (;;) {
        int x = ask(a, b);
        if (x == a) {
          res.emplace_back(a, b);
          in_tree[b] = true;
          break;
        }
        if (in_tree[x]) a = x;
        else b = x;
      }
    }

    cout << "! ";
    for (auto [a, b] : res) cout << a << ' ' << b << ' ';
    cout << endl << flush;
  }
  return 0;
}
