#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int L, R;
  cin >> L >> R;
  int cur_l = 0, cur_r = L;
  vector<pair<int, int>> res;
  if (L == 0) {
    int best = (1LL << (63 - __builtin_clzll(R)));
    res.push_back({0, best});
    cur_r = best;
  }
  while (cur_r < R) {
    cur_l = cur_r;
    int best = 0, tmp = cur_l;
    while (tmp > 0 && tmp % 2 == 0) {
      best++;
      tmp /= 2;
    }
    for (int i = best; i >= 0; i--) {
      if ((cur_l / (1LL << i) + 1) * (1LL << i) <= R) {
        cur_r = (cur_l / (1LL << i) + 1) * (1LL << i);
        break;
      }
    }
    res.push_back({cur_l, cur_r});
  }
  cout << res.size() << '\n';
  for (auto [l, r] : res) cout << l << ' ' << r << '\n';
  return 0;
}
