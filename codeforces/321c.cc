#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;

  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<bool> visited(n);
  vector<int> subtree_size(n);
  auto compute_subtree_size = [&](auto&& self, int u, int p) -> void {
    subtree_size[u] = 1;
    for (int v : g[u]) {
      if (v == p or visited[v]) continue;
      self(self, v, u);
      subtree_size[u] += subtree_size[v];
    }
    };

  auto find_centroid = [&](auto&& self, int u, int p, int tot_size) -> int {
    for (int v : g[u]) {
      if (v == p or visited[v]) continue;
      if (subtree_size[v] * 2 > tot_size) return self(self, v, u, tot_size);
    }
    return u;
    };

  vector<int> res(n);
  auto decompose = [&](auto&& self, int u, int depth) -> void {
    compute_subtree_size(compute_subtree_size, u, -1);
    int centroid = find_centroid(find_centroid, u, -1, subtree_size[u]);
    visited[centroid] = true;
    res[centroid] = depth;
    for (int v : g[centroid]) {
      if (visited[v]) continue;
      self(self, v, depth + 1);
    }
    };

  decompose(decompose, 0, 0);
  for (auto& c : res) cout << static_cast<char>(c + 'A') << ' ';
  cout << '\n';
  return 0;
}
