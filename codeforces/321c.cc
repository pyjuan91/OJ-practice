#include <bits/stdc++.h>
using namespace std;

const int kMax = 1e5 + 5;
int n, u, v, sz[kMax], res[kMax];
vector<int> g[kMax];
bool vis[kMax];

void tree_resize(int u, int p) {
  sz[u] = 1;
  for (int v : g[u]) {
    if (v == p || vis[v]) continue;
    tree_resize(v, u);
    sz[u] += sz[v];
  }
}

int get_centroid(int u, int p, int n) {
  for (int v : g[u]) {
    if (v == p || vis[v]) continue;
    if (sz[v] > n / 2) return get_centroid(v, u, n);
  }
  return u;
}

void chaewon(int u, int d) {
  tree_resize(u, 0);
  int c = get_centroid(u, 0, sz[u]);
  vis[c] = true;
  res[c] = d;
  for (int v : g[c]) {
    if (vis[v]) continue;
    chaewon(v, d + 1);
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  chaewon(1, 0);
  for (int i = 1; i <= n; i++) cout << (char)('A' + res[i]) << ' ';
  return 0;
}