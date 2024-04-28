#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
  int n;
  vector<vector<int>> graph;
  vector<int> sum_of_dist, sub_sz, dist_from_zero;

  void trans_to_graph(vector<vector<int>>& edges) {
    graph.resize(n);
    for (auto edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }
  }

  void dfs1(int cur_node, int prev_node) {
    for (int next_node : graph[cur_node]) {
      if (next_node == prev_node) {
        continue;
      }
      dist_from_zero[next_node] = dist_from_zero[cur_node] + 1;
      dfs1(next_node, cur_node);
      sub_sz[cur_node] += sub_sz[next_node];
    }
  }

  void dfs2(int cur_node, int prev_node) {
    for (int next_node : graph[cur_node]) {
      if (next_node == prev_node) {
        continue;
      }
      sum_of_dist[next_node] =
          sum_of_dist[cur_node] - sub_sz[next_node] + n - sub_sz[next_node];
      dfs2(next_node, cur_node);
    }
  }

  void calculate_sum_of_dist() {
    sum_of_dist.resize(n, 0);
    sub_sz.resize(n, 1);
    dist_from_zero.resize(n, 0);
    dfs1(0, -1);
    sum_of_dist[0] =
        accumulate(dist_from_zero.begin(), dist_from_zero.end(), 0);
    dfs2(0, -1);
  }

 public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    this->n = n;
    trans_to_graph(edges);
    calculate_sum_of_dist();
    return sum_of_dist;
  }
};
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> edges;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    edges.push_back({u, v});
  }
  Solution sol;
  vector<int> ans = sol.sumOfDistancesInTree(n, edges);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}