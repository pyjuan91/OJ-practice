#include <bits/stdc++.h>
#include <atcoder/modint>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;
using mint = atcoder::modint998244353;

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n, x;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 2; i <= n; i++) {
      cin >> x;
      g[x].push_back(i);
      g[i].push_back(x);
    }
    vector<int> bfs_order;
    vector<int> parent(n + 1, 0);
    vector<int> depth(n + 1, 0);
    vector<vector<int>> elements_in_depth(n + 1);
    queue<int> q;
    q.push(1);
    depth[1] = 1;
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      bfs_order.push_back(node);
      elements_in_depth[depth[node]].push_back(node);
      for (auto& child : g[node]) {
        if (depth[child] == 0) {
          depth[child] = depth[node] + 1;
          parent[child] = node;
          q.push(child);
        }
      }
    }
    debug(bfs_order);
    debug(depth);
    debug(parent);
    vector<mint> dp(n + 1, 1);
    int cur_depth = depth[bfs_order.back()];
    mint sum_of_cur_depth = 0, sum_of_prev_depth = 0;
    for (int i = bfs_order.size() - 1; i >= 0; i--) {
      int node = bfs_order[i];
      if (depth[node] == cur_depth) {
        dp[node] += sum_of_prev_depth;
        if (parent[node] != 1)dp[parent[node]] -= dp[node];
        sum_of_cur_depth += dp[node];
        debug(node, dp[node].val());
        debug(sum_of_cur_depth.val());
      }
      else {
        cur_depth = depth[node];
        sum_of_prev_depth = sum_of_cur_depth;
        dp[node] += sum_of_prev_depth;
        if (parent[node] != 1) dp[parent[node]] -= dp[node];
        sum_of_cur_depth = dp[node];
        debug(node, dp[node].val(), sum_of_prev_depth.val());
        debug(sum_of_cur_depth.val());
      }
    }
    cout << dp[1].val() << '\n';
  }
  return 0;
}
