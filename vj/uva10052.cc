#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t, n, m;
  cin >> t;
  for (int kase = 1; kase <= t; kase++) {
    cin >> n >> m;
    vector<string> names(n);
    unordered_map<string, int> name_to_id;
    for (int i = 0; i < n; i++) {
      cin >> names[i];
      name_to_id[names[i]] = i;
    }

    string u_name, v_name;
    vector<unordered_set<int>> g(n);
    for (int i = 0; i < m; i++) {
      cin >> u_name >> v_name;
      int u_id = name_to_id[u_name], v_id = name_to_id[v_name];
      g[u_id].insert(v_id);
      g[v_id].insert(u_id);
    }

    vector<int> color(n, 0);
    function<bool(int)> drawing = [&](int u) {
      int adj_color = 0;
      for (int v : g[u]) adj_color |= color[v];
      for (int c = 1; c <= 8; c <<= 1) {
        if (!(adj_color & c)) {
          color[u] = c;

          set<pair<int, int>, greater<pair<int, int>>> s;
          for (auto v : g[u]) {
            if (!color[v]) {
              int adj_color = 0;
              for (int w : g[v]) adj_color |= color[w];
              s.insert({__builtin_popcount(adj_color), v});
            }
          }

          for (auto [_, v] : s) {
            if (!color[v] && !drawing(v)) {
              color[u] = 0;
              break;
            }
          }
          if (color[u]) return true;
        }
      }
      if (!color[u]) return false;
      return true;
    };

    for (int i = 0; i < n; i++) {
      if (!color[i]) drawing(i);
    }

    if (kase > 1) cout << "\n";
    cout << "Case #" << kase << "\n";

    vector<int> res[9];
    for (int i = 0; i < n; i++) res[color[i]].push_back(i);

    for (int c = 1; c <= 8; c <<= 1) {
      cout << res[c].size() << "\n";
      for (int i = 0; i < res[c].size(); i++) {
        cout << names[res[c][i]] << " \n"[i + 1 == res[c].size()];
      }
    }
  }
  return 0;
}