#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMax = 1e5 + 5;
int n, m, a[kMax], u, v;
vector<int> g[kMax];
int importance[kMax], parent[kMax], tree_sz[kMax];
set<pair<int, int>> sons[kMax];

void zuha(int u, int p) {
  parent[u] = p;
  tree_sz[u] = -1;
  importance[u] = a[u];
  for (int v : g[u]) {
    if (v != p) {
      zuha(v, u);
      importance[u] += importance[v];
      tree_sz[u] += tree_sz[v];
      sons[u].insert(make_pair(tree_sz[v], v));
    }
  }
}

void update(int u) {
  if (!sons[u].empty()) {
    auto [sz, v] = *sons[u].begin();
    sons[u].erase(sons[u].begin());
    int par = parent[u];
    auto it = sons[par].find(make_pair(tree_sz[u], u));
    sons[par].erase(it);
    sons[par].insert({tree_sz[u], v});
    int org_sz = tree_sz[u], org_impor = importance[u];
    int org_sub_sz = tree_sz[v], org_sub_impor = importance[v];
    tree_sz[u] -= org_sub_sz;
    importance[u] -= org_sub_impor;
    tree_sz[v] = org_sz;
    importance[v] = org_impor;
    sons[v].insert(make_pair(tree_sz[u], u));
    parent[v] = par;
    parent[u] = v;
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i < n; i++) {
    std::cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  zuha(1, 0);
  while (m--) {
    std::cin >> u >> v;
    if (u == 1)
      cout << importance[v] << '\n';
    else
      update(v);
  }
  return 0;
}
