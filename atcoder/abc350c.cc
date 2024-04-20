#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n + 1), pos(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i], pos[a[i]] = i;
  vector<pair<int, int>> res;
  for (int i = 1; i <= n; i++) {
    if (pos[i] != i) {
      res.push_back({min(i, pos[i]), max(i, pos[i])});
      swap(a[pos[i]], a[i]);
      pos[a[pos[i]]] = pos[i];
      pos[a[i]] = i;
    }
  }
  cout << res.size() << '\n';
  for (auto [x, y] : res) cout << x << ' ' << y << '\n';
  return 0;
}
