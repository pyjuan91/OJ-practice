#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
using namespace std;

class Solution {
 public:
  vector<int> findSubtreeSizes(vector<int>& parent, string s) {
    const int n = parent.size();
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
      int u = parent[i], v = i;
      g[u].push_back(v);
    }
    unordered_map<char, vector<int>> closet;
    [&](this auto&& dfs, int u) -> void {
      if (closet.count(s[u])) {
        parent[u] = closet[s[u]].back();
      }
      closet[s[u]].push_back(u);
      for (const auto& v : g[u]) {
        dfs(v);
      }
      closet[s[u]].pop_back();
      if (closet[s[u]].empty()) {
        closet.erase(s[u]);
      }
    }(0);
    debug(parent);

    g.assign(n, vector<int>());
    for (int i = 1; i < n; i++) {
      int u = parent[i], v = i;
      g[u].push_back(v);
    }

    vector<int> tree_size(n);
    [&](this auto&& dfs, int u) -> void {
      tree_size[u] = 1;
      for (const auto& v : g[u]) {
        dfs(v);
        tree_size[u] += tree_size[v];
      }
    }(0);

    return tree_size;
  }
};

int main() {
  vector<int> parent = {-1, 0, 0, 1, 1, 1};
  string s = "abaabc";
  auto sol = new Solution();
  auto res = sol->findSubtreeSizes(parent, s);
  debug(res);
  return 0;
}