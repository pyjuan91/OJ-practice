#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int seg[4 * maxn], n, m, x, a[maxn];

void update(int left, int right, int pos, int val, int id = 1) {
  if (left == right) {
    seg[id] = val;
    return;
  }
  int mid = (left + right) >> 1;
  if (pos <= mid)
    update(left, mid, pos, val, id << 1);
  else
    update(mid + 1, right, pos, val, id << 1 | 1);
  seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
}

int query(int left, int right, int val, int id = 1) {
  if (left == right) return left;
  int mid = (left + right) >> 1;
  if (seg[id << 1] >= val)
    return query(left, mid, val, id << 1);
  else
    return query(mid + 1, right, val, id << 1 | 1);
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    update(1, n, i, a[i]);
  }
  while (m--) {
    cin >> x;
    if (seg[1] < x)
      cout << "0 ";
    else {
      int pos = query(1, n, x);
      cout << pos << " ";
      a[pos] -= x;
      update(1, n, pos, a[pos]);
    }
  }

  return 0;
}
