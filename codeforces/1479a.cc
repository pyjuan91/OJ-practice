#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;

  auto ask = [&](int i) -> int {
    cout << "? " << i << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
  };

  auto answer = [&](int x) -> void {
    cout << "! " << x << endl;
    cout.flush();
  };

  if (n < 100) {
    for (int i = 1; i <= n; i++) {
      if (ask(i) == 1) {
        answer(i);
        return 0;
      }
    }
  }

  int l = 1, r = n;
  while (l < r) {
    int m = (l + r) / 2;
    int am = ask(m), am1 = ask(m + 1);
    if (am < am1) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  answer(l);
  return 0;
}
