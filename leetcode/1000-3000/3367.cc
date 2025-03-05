#include <bits/stdc++.h>

#include "debug.cc"
using namespace std;

class Solution {
 public:
  int64_t maximizeSumOfWeights(vector<vector<int32_t>>& edges, int32_t k) {
    int32_t n = static_cast<int32_t>(edges.size()) + 1;

    // Transform the input to adjacency list.
    vector adj(n, set<pair<int32_t, int32_t>>());
    for (auto& edge : edges) {
      int32_t u = edge[0], v = edge[1], w = edge[2];
      adj[u].insert({v, w});
      adj[v].insert({u, w});
    }

    // DFS the potential states.
    // return two values:
    // v1 means current node only connects at most k-1 children.
    // v2 means current node connects at most k children.
    auto dfs = [&](auto&& self, int32_t cur_node,
                   int32_t parent_node) -> pair<int64_t, int64_t> {
      int64_t res = 0;
      vector<int64_t> improvements;

      for (auto [next_node, weight] : adj[cur_node]) {
        if (next_node == parent_node) continue;
        auto [child_v1, child_v2] = self(self, next_node, cur_node);
        res += child_v2;
        int64_t improvement = max(0L, child_v1 + weight - child_v2);
        improvements.push_back(improvement);
      }

      sort(improvements.rbegin(), improvements.rend());
      int64_t sum_v1 = res, sum_v2;
      for (int i = 0;
           i < (k - 1) and i < static_cast<int32_t>(improvements.size()); i++) {
        sum_v1 += improvements[i];
      }

      if (static_cast<int32_t>(improvements.size()) >= k) {
        sum_v2 = sum_v1 + improvements[k - 1];
      } else {
        sum_v2 = sum_v1;
      }

      return {sum_v1, sum_v2};
    };

    return dfs(dfs, 0, -1).second;
  }
};

int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> edges(n, vector<int>(3));
  for (int i = 0; i < n; i++) {
    cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
  }
  Solution sol;
  cout << sol.maximizeSumOfWeights(edges, k) << endl;
  return 0;
}