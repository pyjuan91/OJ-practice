#include <bits/stdc++.h>

#include <atcoder/lazysegtree>
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