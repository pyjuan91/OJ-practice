#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMax = 5e5 + 5;
int n, m, op, L, R;
string s;
int a[kMax], lazy[4 * kMax] = {};
enum StringState { Bad, OneOne, ZeroZero, OneZero, ZeroOne, EmptyString };
StringState t[4 * kMax];

StringState flip(StringState state) {
  switch (state) {
    case OneOne:
      return ZeroZero;
    case ZeroZero:
      return OneOne;
    case OneZero:
      return ZeroOne;
    case ZeroOne:
      return OneZero;
    case EmptyString:
      return EmptyString;
    default:
      return Bad;
  }
}

StringState merge(StringState left, StringState right) {
  switch (left) {
    case Bad:
      return Bad;
    case OneOne:
      if (right == OneOne || right == OneZero || right == Bad) return Bad;
      if (right == ZeroZero) return OneZero;
      return OneOne;
    case ZeroZero:
      if (right == ZeroZero || right == ZeroOne || right == Bad) return Bad;
      if (right == OneOne) return ZeroOne;
      return ZeroZero;
    case OneZero:
      if (right == ZeroZero || right == ZeroOne || right == Bad) return Bad;
      if (right == OneOne) return OneOne;
      return OneZero;
    case ZeroOne:
      if (right == OneOne || right == OneZero || right == Bad) return Bad;
      if (right == ZeroZero) return ZeroZero;
      return ZeroOne;
    default:
      return right;
  }
}

void build(int a[], int v, int tl, int tr) {
  if (tl == tr) {
    if (a[tl])
      t[v] = OneOne;
    else
      t[v] = ZeroZero;
  } else {
    int tm = (tl + tr) / 2;
    build(a, v * 2, tl, tm);
    build(a, v * 2 + 1, tm + 1, tr);
    auto left = t[v * 2], right = t[v * 2 + 1];
    t[v] = merge(left, right);
  }
}

void push(int v) {
  if (lazy[v]) {
    t[v * 2] = flip(t[v * 2]);
    lazy[v * 2] ^= 1;
    t[v * 2 + 1] = flip(t[v * 2 + 1]);
    lazy[v * 2 + 1] ^= 1;
    lazy[v] = 0;
  }
}

void update(int v, int tl, int tr, int l, int r) {
  if (l > r) return;
  if (l == tl && tr == r) {
    t[v] = flip(t[v]);
    lazy[v] ^= 1;
  } else {
    push(v);
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(r, tm));
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    auto left = t[v * 2], right = t[v * 2 + 1];
    t[v] = merge(left, right);
  }
}

StringState query(int v, int tl, int tr, int l, int r) {
  if (l > r) return EmptyString;
  if (l == tl && tr == r) return t[v];
  push(v);
  int tm = (tl + tr) / 2;
  auto left = query(v * 2, tl, tm, l, min(r, tm));
  auto right = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
  return merge(left, right);
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m >> s;
  s = " " + s;
  for (int i = 1; i <= n; i++) {
    a[i] = (s[i] == '1') ? 1 : 0;
  }
  build(a, 1, 1, n);
  while (m--) {
    cin >> op >> L >> R;
    if (op == 2)
      cout << (query(1, 1, n, L, R) != Bad ? "Yes\n" : "No\n");
    else
      update(1, 1, n, L, R);
  }
  return 0;
}
