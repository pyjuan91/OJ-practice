#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMax = 1e5 + 5;
int n, m, r, kMod, op, x, y, z, cnt = 0;
int a[kMax] = {}, dep[kMax] = {}, fa[kMax] = {}, siz[kMax] = {},
    hson[kMax] = {};
int nid[kMax] = {}, na[kMax] = {}, ltop[kMax] = {};
int seg[kMax << 2] = {}, tag[kMax << 2] = {};
vector<int> g[kMax];

void dfs1(int u, int f) {
  dep[u] = dep[f] + 1;
  fa[u] = f;
  siz[u] = 1;
  for (auto v : g[u]) {
    if (v == f) continue;
    dfs1(v, u);
    siz[u] += siz[v];
    if (siz[v] > siz[hson[u]]) hson[u] = v;
  }
}

void dfs2(int u, int cur_ltop) {
  nid[u] = ++cnt;
  na[cnt] = a[u];
  ltop[u] = cur_ltop;
  if (hson[u]) dfs2(hson[u], cur_ltop);
  for (auto v : g[u]) {
    if (v == fa[u] || v == hson[u]) continue;
    dfs2(v, v);
  }
}

void build(int u, int l, int r) {
  if (l == r) {
    seg[u] = na[l] % kMod;
    return;
  }
  int mid = (l + r) >> 1;
  build(u << 1, l, mid);
  build(u << 1 | 1, mid + 1, r);
  seg[u] = (seg[u << 1] + seg[u << 1 | 1]) % kMod;
}

void push_down(int u, int l, int r) {
  if (tag[u]) {
    int mid = (l + r) >> 1;
    seg[u << 1] = (seg[u << 1] + tag[u] * (mid - l + 1)) % kMod;
    seg[u << 1 | 1] = (seg[u << 1 | 1] + tag[u] * (r - mid)) % kMod;
    tag[u << 1] = (tag[u << 1] + tag[u]) % kMod;
    tag[u << 1 | 1] = (tag[u << 1 | 1] + tag[u]) % kMod;
    tag[u] = 0;
  }
}

int query(int u, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return seg[u];
  push_down(u, l, r);
  int mid = (l + r) >> 1, res = 0;
  if (ql <= mid) res = (res + query(u << 1, l, mid, ql, qr)) % kMod;
  if (qr > mid) res = (res + query(u << 1 | 1, mid + 1, r, ql, qr)) % kMod;
  return res;
}

void update(int u, int l, int r, int ql, int qr, int k) {
  if (ql <= l && r <= qr) {
    seg[u] = (seg[u] + k * (r - l + 1)) % kMod;
    tag[u] = (tag[u] + k) % kMod;
    return;
  }
  push_down(u, l, r);
  int mid = (l + r) >> 1;
  if (ql <= mid) update(u << 1, l, mid, ql, qr, k);
  if (qr > mid) update(u << 1 | 1, mid + 1, r, ql, qr, k);
  seg[u] = (seg[u << 1] + seg[u << 1 | 1]) % kMod;
}

int query_path(int u, int v) {
  int res = 0;
  while (ltop[u] != ltop[v]) {
    if (dep[ltop[u]] < dep[ltop[v]]) swap(u, v);
    res = (res + query(1, 1, n, nid[ltop[u]], nid[u])) % kMod;
    u = fa[ltop[u]];
  }
  if (dep[u] > dep[v]) swap(u, v);
  res = (res + query(1, 1, n, nid[u], nid[v])) % kMod;
  return res;
}

void update_path(int u, int v, int k) {
  k %= kMod;
  while (ltop[u] != ltop[v]) {
    if (dep[ltop[u]] < dep[ltop[v]]) swap(u, v);
    update(1, 1, n, nid[ltop[u]], nid[u], k);
    u = fa[ltop[u]];
  }
  if (dep[u] > dep[v]) swap(u, v);
  update(1, 1, n, nid[u], nid[v], k);
}

int query_subtree(int u) { return query(1, 1, n, nid[u], nid[u] + siz[u] - 1); }

void update_subtree(int u, int k) {
  update(1, 1, n, nid[u], nid[u] + siz[u] - 1, k);
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m >> r >> kMod;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  dfs1(r, 0);
  dfs2(r, r);
  build(1, 1, n);

  while (m--) {
    cin >> op >> x;
    if (op == 1) {
      cin >> y >> z;
      update_path(x, y, z);
    } else if (op == 2) {
      cin >> y;
      cout << query_path(x, y) << '\n';
    } else if (op == 3) {
      cin >> z;
      update_subtree(x, z);
    } else {
      cout << query_subtree(x) << '\n';
    }
  }
  return 0;
}
