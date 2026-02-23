#include <bits/stdc++.h>
using namespace std;

const int kMax = 1e5 + 5;
vector<int> lp(kMax + 1);
vector<int> pr;

int init = []() {
  for (int i = 2; i <= kMax; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; i * pr[j] <= kMax; ++j) {
      lp[i * pr[j]] = pr[j];
      if (pr[j] == lp[i]) {
        break;
      }
    }
  }
  return 0;
}();

struct DisjointSetUnion {
 public:
  DisjointSetUnion() : _n(0) {}
  explicit DisjointSetUnion(int n) : _n(n), parent_or_size(n, -1) {}

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

class Solution {
 public:
  long long countPaths(int n, vector<vector<int>>& edges) {
    vector<vector<int>> g(n + 1);
    auto dsu = DisjointSetUnion(n + 1);
    for (const auto& edge : edges) {
      int u = edge[0], v = edge[1];
      g[u].push_back(v);
      g[v].push_back(u);
      if (lp[u] != u and lp[v] != v) dsu.merge(u, v);
    }
    long long res = 0;
    for (int i = 2; i <= n; i++) {
      if (lp[i] == i) {
        long long pref = 0;
        for (const auto& v : g[i]) {
          if (lp[v] == v) continue;
          int ts = dsu.size(v);
          res += pref * ts;
          pref += ts;
        }
        res += pref;
      }
    }
    return res;
  }
};

int main() { return 0; }