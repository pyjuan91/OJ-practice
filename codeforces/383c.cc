#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMax = 2e5 + 5;
int n, m, a[kMax], tin[kMax], tout[kMax], op, x, val, u, v;
vector<int> g[kMax];
int t[kMax] = {}, scalar[kMax];

int lowbit(int x) { return x & -x; }

void add(int x, int v) {
  for (int i = x; i <= n; i += lowbit(i)) t[i] += v;
}

int sum(int x) {
  int res = 0;
  for (int i = x; i > 0; i -= lowbit(i)) res += t[i];
  return res;
}

void dfs(int u, int p) {
  tin[u] = ++tin[0];
  for (auto v : g[u]) {
    scalar[v] = -1 * scalar[u];
    if (v != p) dfs(v, u);
  }
  tout[u] = tin[0];
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  scalar[1] = 1;
  dfs(1, 0);
  while (m--) {
    cin >> op;
    if (op == 1) {
      cin >> x >> val;
      add(tin[x], val * scalar[x]);
      add(tout[x] + 1, -val * scalar[x]);
    } else {
      cin >> x;
      cout << a[x] + sum(tin[x]) * scalar[x] << '\n';
    }
  }
  return 0;
}