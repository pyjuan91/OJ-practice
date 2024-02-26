#include <bits/stdc++.h>
#define int long long
using namespace std;
struct dsu {
 public:
  dsu() : _n(0) {}
  explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

  int merge(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    int x = leader(a), y = leader(b);
    if (x == y) return x;
    if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
    parent_or_size[x] += parent_or_size[y];
    parent_or_size[y] = x;
    return x;
  }

  bool same(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    return leader(a) == leader(b);
  }

  int leader(int a) {
    assert(0 <= a && a < _n);
    if (parent_or_size[a] < 0) return a;
    return parent_or_size[a] = leader(parent_or_size[a]);
  }

  int size(int a) {
    assert(0 <= a && a < _n);
    return -parent_or_size[leader(a)];
  }

  std::vector<std::vector<int>> groups() {
    std::vector<int> leader_buf(_n), group_size(_n);
    for (int i = 0; i < _n; i++) {
      leader_buf[i] = leader(i);
      group_size[leader_buf[i]]++;
    }
    std::vector<std::vector<int>> result(_n);
    for (int i = 0; i < _n; i++) {
      result[i].reserve(group_size[i]);
    }
    for (int i = 0; i < _n; i++) {
      result[leader_buf[i]].push_back(i);
    }
    result.erase(
        std::remove_if(result.begin(), result.end(),
                       [&](const std::vector<int>& v) { return v.empty(); }),
        result.end());
    return result;
  }

 private:
  int _n;
  // root node: -1 * component size
  // otherwise: parent
  std::vector<int> parent_or_size;
};
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  vector<tuple<int, int, int>> edges(m);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    edges[i] = {w, u, v};
  }

  int res = k - 1;

  auto check = [&](vector<tuple<int, int, int>>& edges) {
    dsu d(n);
    int cur = 0;
    bool ok = true;
    for (auto [w, u, v] : edges) {
      if (d.same(u, v)) {
        ok = false;
        break;
      }
      d.merge(u, v);
      cur = (cur + w) % k;
    }
    if (ok) res = min(res, cur);
  };

  vector<tuple<int, int, int>> g;

  function<void(int)> zuha = [&](int i) {
    if (g.size() == n - 1) {
      // for (auto [w, u, v] : g) {
      //   std::cout << w << ' ' << u << ' ' << v << '\n';
      // }
      // std::cout << '\n';
      check(g);
      return;
    }
    if (i == m) return;
    g.push_back(edges[i]);
    zuha(i + 1);
    g.pop_back();
    zuha(i + 1);
  };
  zuha(0);
  std::cout << res << '\n';
  return 0;
}
