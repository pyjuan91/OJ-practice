#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, x, l = 0, r = 1;
  long long ans = 0;
  char op;
  cin >> n >> m;
  while (m--) {
    cin >> op >> x;
    x--;
    auto move_hand = [&](int from, int to, int obstacle) {
      if (from > to) swap(from, to);
      if (obstacle >= from and obstacle <= to) return n - to + from;
      return to - from;
      };
    if (op == 'R') {
      ans += static_cast<long long>(move_hand(r, x, l));
      r = x;
    }
    else {
      ans += static_cast<long long>(move_hand(l, x, r));
      l = x;
    }
  }
  cout << ans << '\n';
  return 0;
}
