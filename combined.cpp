#include <bits/stdc++.h>


#include <algorithm>
#include <cassert>
#include <functional>
#include <vector>


#ifdef _MSC_VER
#include <intrin.h>
#endif

#if __cplusplus >= 202002L
#include <bit>
#endif

namespace atcoder {

namespace internal {

#if __cplusplus >= 202002L

using std::bit_ceil;

#else

// @return same with std::bit::bit_ceil
unsigned int bit_ceil(unsigned int n) {
    unsigned int x = 1;
    while (x < (unsigned int)(n)) x *= 2;
    return x;
}

#endif

// @param n `1 <= n`
// @return same with std::bit::countr_zero
int countr_zero(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

// @param n `1 <= n`
// @return same with std::bit::countr_zero
constexpr int countr_zero_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

#if __cplusplus >= 201703L

template <class S,
          auto op,
          auto e,
          class F,
          auto mapping,
          auto composition,
          auto id>
struct lazy_segtree {
    static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>,
                  "op must work as S(S, S)");
    static_assert(std::is_convertible_v<decltype(e), std::function<S()>>,
                  "e must work as S()");
    static_assert(
        std::is_convertible_v<decltype(mapping), std::function<S(F, S)>>,
        "mapping must work as S(F, S)");
    static_assert(
        std::is_convertible_v<decltype(composition), std::function<F(F, F)>>,
        "composition must work as F(F, F)");
    static_assert(std::is_convertible_v<decltype(id), std::function<F()>>,
                  "id must work as F()");

#else

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {

#endif

  public:
    lazy_segtree() : lazy_segtree(0) {}
    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        size = (int)internal::bit_ceil((unsigned int)(_n));
        log = internal::countr_zero((unsigned int)size);
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

}  // namespace atcoder

using namespace std;

struct S {
  long long x;
  int len;
};
using F = long long;

S op(S a, S b) { return {a.x ^ b.x, a.len + b.len}; }
S e() { return {0, 0}; }
S mapping(F f, S s) { return {s.x ^ ((s.len & 1) ? f : 0), s.len}; }
F composition(F f, F g) { return f ^ g; }  // f is the newer tag
F id() { return 0; }

using Seg = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;

struct LCA {
  int n, LOG;
  vector<int> depth;
  vector<vector<int>>
      up;  // up[k][v] = 2^k-th ancestor of v; root maps to itself

  LCA(const vector<vector<int>>& adj, int root)
      : n((int)adj.size()),
        LOG(max(1,
                (int)bit_width((unsigned)n))),  // smallest LOG with 2^LOG > n
        depth(n, 0),
        up(LOG, vector<int>(n)) {
    // BFS instead of recursive DFS: a 2e5-long chain can blow the stack on some
    // judges
    vector<int> order;
    order.reserve(n);
    vector<char> seen(n, 0);
    order.push_back(root);
    seen[root] = 1;
    up[0][root] = root;
    for (size_t i = 0; i < order.size(); ++i) {
      int v = order[i];
      for (int w : adj[v]) {
        if (seen[w]) continue;
        seen[w] = 1;
        up[0][w] = v;
        depth[w] = depth[v] + 1;
        order.push_back(w);
      }
    }
    // k-outer loop: each level only reads the previous level, row-wise access
    for (int k = 1; k < LOG; ++k)
      for (int v = 0; v < n; ++v) up[k][v] = up[k - 1][up[k - 1][v]];
  }

  // Jump d steps up (d <= depth[v] assumed)
  int kth_ancestor(int v, int d) const {
    for (int k = 0; d > 0; ++k, d >>= 1)
      if (d & 1) v = up[k][v];
    return v;
  }

  int query(int u, int v) const {
    if (depth[u] < depth[v]) swap(u, v);
    u = kth_ancestor(u, depth[u] - depth[v]);  // Step A
    if (u == v) return u;                      // Step B
    for (int k = LOG - 1; k >= 0; --k)         // Step C
      if (up[k][u] != up[k][v]) {
        u = up[k][u];
        v = up[k][v];
      }
    return up[0][u];
  }

  int dist(int u, int v) const {
    return depth[u] + depth[v] - 2 * depth[query(u, v)];
  }
};

class Solution {
 public:
  vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s,
                              vector<string>& queries) {
    vector<vector<int>> g(n);
    for (const auto& edge : edges) {
      g[edge[0]].push_back(edge[1]);
      g[edge[1]].push_back(edge[0]);
    }

    vector<int> node_val;
    for (const char& c : s) {
      node_val.push_back(1 << static_cast<int>(c - 'a'));
    }

    vector<int> subtree_size(n);
    vector<S> dfs_tree;
    vector<int> dfs_order(n);
    vector<int> root_xor(n);
    int order = 0;
    auto dfs = [&](this auto&& dfs, int cur_node, int prev_node) -> void {
      dfs_order[cur_node] = order++;
      subtree_size[cur_node] = 1;
      root_xor[cur_node] ^= node_val[cur_node];
      dfs_tree.emplace_back(root_xor[cur_node], 1);
      for (const auto& next_node : g[cur_node]) {
        if (next_node != prev_node) {
          root_xor[next_node] ^= root_xor[cur_node];
          dfs(next_node, cur_node);
          subtree_size[cur_node] += subtree_size[next_node];
        }
      }
    };

    dfs(0, -1);
    Seg seg(dfs_tree);
    LCA lca(g, 0);

    vector<bool> res;
    for (const auto& query : queries) {
      stringstream ss(query);
      string op_type;
      ss >> op_type;
      if (op_type == "update") {
        int u;
        char c;
        ss >> u >> c;
        seg.apply(dfs_order[u], dfs_order[u] + subtree_size[u], node_val[u]);
        node_val[u] = (1 << static_cast<int>(c - 'a'));
        seg.apply(dfs_order[u], dfs_order[u] + subtree_size[u], node_val[u]);
      } else {
        int u, v;
        ss >> u >> v;
        int ancestor = lca.query(u, v);
        auto [u_xor, _] = seg.get(dfs_order[u]);
        auto [v_xor, __] = seg.get(dfs_order[v]);
        int path_xor = node_val[ancestor] ^ u_xor ^ v_xor;
        res.push_back(std::popcount(static_cast<unsigned int>(path_xor)) <= 1);
      }
    }

    return res;
  }
};
