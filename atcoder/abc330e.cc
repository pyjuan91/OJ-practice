#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMax = 2e5 + 5;
int n, m, x, y, a[kMax];
pair<int, int> t[4 * kMax];

void update(int v, int tl, int tr, int pos, int new_val) {
  if (tl == tr) {
    t[v].second = pos;
    t[v].first += new_val;
  } else {
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
      update(v * 2, tl, tm, pos, new_val);
    } else {
      update(v * 2 + 1, tm + 1, tr, pos, new_val);
    }
    t[v] = min(t[v * 2], t[v * 2 + 1]);
  }
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) update(1, 1, n, i, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i]++;
    if (a[i] <= n) update(1, 1, n, a[i], 1);
  }
  while (m--) {
    cin >> x >> y;
    if (a[x] <= n) update(1, 1, n, a[x], -1);
    a[x] = y + 1;
    if (a[x] <= n) update(1, 1, n, a[x], 1);
    cout << (t[1].first == 0 ? t[1].second - 1 : n) << '\n';
  }
  return 0;
}
