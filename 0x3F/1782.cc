#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> countPairs(int n, vector<vector<int>>& edges,
                         vector<int>& queries) {
    vector<int> degree(n, 0);
    map<pair<int, int>, int> shared_link_cnt;
    for (const auto& edge : edges) {
      int u = min(edge[0], edge[1]) - 1;
      int v = max(edge[0], edge[1]) - 1;
      degree[u]++;
      degree[v]++;
      shared_link_cnt[make_pair(u, v)]++;
    }
    vector<int> sorted_degree = degree;
    sort(sorted_degree.begin(), sorted_degree.end());

    vector<int> res_vec;
    for (const int& query : queries) {
      int res = 0;
      // count deg(node_a) + deg(node_b) > query, O(n lg n)
      for (int i = 0; i < n; i++) {
        auto iter = upper_bound(sorted_degree.begin(), sorted_degree.end(),
                                query - sorted_degree[i]);
        int iter_idx = iter - sorted_degree.begin();
        res += n - max(i + 1, iter_idx);
      }
      // substract overcount where deg(node_a) + deg(node_b) - shared(node_a,
      // node_b) <= query, O(m lg m)
      for (const auto& [key_pair, value_number] : shared_link_cnt) {
        int u = key_pair.first, v = key_pair.second;
        bool cond1 = degree[u] + degree[v] > query;
        bool cond2 = degree[u] + degree[v] - value_number <= query;
        if (cond1 and cond2) res--;
      }
      res_vec.push_back(res);
    }

    return res_vec;
  }
};

int main() { return 0; }