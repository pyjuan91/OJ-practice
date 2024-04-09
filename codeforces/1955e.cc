#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  string s;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    reverse(s.begin(), s.end());
    bitset<5005> b(s);

    auto check = [&](int x) {
      auto a = b;
      bitset<5005> need_flip;
      for (int i = 0; i < n - x + 1; i++) {
        if (i) need_flip[i] = need_flip[i] ^ need_flip[i - 1];
        if (!(a[i] ^ need_flip[i])) {
          a[i].flip();
          need_flip[i].flip();
          need_flip[i + x].flip();
        }
      }
      for (int i = n - x + 1; i < n; i++) {
        if (i) need_flip[i] = need_flip[i] ^ need_flip[i - 1];
        if (!(a[i] ^ need_flip[i])) {
          return false;
        }
      }
      return true;
    };

    for (int res = n; res >= 1; res--) {
      if (check(res)) {
        cout << res << '\n';
        break;
      }
    }
  }
  return 0;
}
