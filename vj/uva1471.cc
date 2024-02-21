#include <bits/stdc++.h>
using namespace std;

const int kMax = 2e5 + 5;
int kase, n, a[kMax], cnt, t[4 * kMax], pre[kMax], suf[kMax], res;
map<int, int> mp;

void update(int v, int tl, int tr, int pos, int new_val) {
  if (tl == tr)
    t[v] = max(new_val, t[v]);
  else {
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      update(v * 2, tl, tm, pos, new_val);
    else
      update(v * 2 + 1, tm + 1, tr, pos, new_val);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
  }
}

int query(int v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (l == tl && r == tr) return t[v];
  int tm = (tl + tr) / 2;
  return max(query(v * 2, tl, tm, l, min(r, tm)),
             query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> kase;
  while (kase--) {
    mp.clear(), cnt = 0, memset(t, 0, sizeof(t)), res = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], mp[a[i]] = 1;
    for (auto& [k, v] : mp) v = cnt++;
    for (int i = 0; i < n; i++) a[i] = mp[a[i]];

    pre[0] = 1;
    for (int i = 1; i < n; i++) {
      pre[i] = (a[i] > a[i - 1]) ? pre[i - 1] + 1 : 1;
    }
    suf[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
      suf[i] = (a[i] < a[i + 1]) ? suf[i + 1] + 1 : 1;
    }

    for (int i = 0; i < n; i++) {
      int pb = (a[i] > 0) ? query(1, 0, n - 1, 0, a[i] - 1) : 0;
      int sf = suf[i];
      res = max(res, pb + sf);
      update(1, 0, n - 1, a[i], pre[i]);
    }
    cout << res << '\n';
  }

  return 0;
}
