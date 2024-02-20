#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMax = 2e5 + 5;
int n, q, op, a, b;
vector<int> g[kMax];
int in[kMax] = {}, sz[kMax], t[4 * kMax], v[kMax], nv[kMax];

void dfs(int u, int p) {
  in[u] = ++in[0];
  nv[in[u]] = v[u];
  sz[u] = 1;
  for (auto& v : g[u]) {
    if (v != p) {
      dfs(v, u);
      sz[u] += sz[v];
    }
  }
}

void build(int id, int tl, int tr) {
  if (tl == tr) {
    t[id] = nv[tl];
  } else {
    int tm = (tl + tr) / 2;
    build(id * 2, tl, tm);
    build(id * 2 + 1, tm + 1, tr);
    t[id] = t[id * 2] + t[id * 2 + 1];
  }
}

void update(int id, int tl, int tr, int pos, int new_val) {
  if (tl == tr) {
    t[id] = new_val;
  } else {
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
      update(id * 2, tl, tm, pos, new_val);
    } else {
      update(id * 2 + 1, tm + 1, tr, pos, new_val);
    }
    t[id] = t[id * 2] + t[id * 2 + 1];
  }
}

int query(int id, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (l == tl && r == tr) return t[id];
  int tm = (tl + tr) / 2;
  return query(id * 2, tl, tm, l, min(r, tm)) +
         query(id * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> v[i];
  for (int i = 1; i < n; i++) {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dfs(1, 0);
  build(1, 1, n);

  while (q--) {
    cin >> op;
    if (op == 1) {
      cin >> a >> b;
      update(1, 1, n, in[a], b);
    } else {
      cin >> a;
      cout << query(1, 1, n, in[a], in[a] + sz[a] - 1) << '\n';
    }
  }

  return 0;
}
