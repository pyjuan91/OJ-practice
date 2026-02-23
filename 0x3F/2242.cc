#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
    const int n = scores.size();
    vector<vector<int>> g(n);
    for (const auto& edge : edges) {
      int u = edge[0], v = edge[1];
      g[u].push_back(v);
      g[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
      sort(g[i].begin(), g[i].end(), [&](const auto& lhs, const auto& rhs) {
        return scores[lhs] > scores[rhs];
      });
    }
    int res = -1;
    for (const auto& edge : edges) {
      auto patty = [&](int u, int v) {
        int u_neighbor = -1, v_neighbor = -1;
        for (const auto& x : g[u]) {
          if (x != v) {
            u_neighbor = x;
            break;
          }
        }
        for (const auto& x : g[v]) {
          if (x != u and x != u_neighbor) {
            v_neighbor = x;
            break;
          }
        }
        if (u_neighbor != -1 and v_neighbor != -1) {
          res = max(res, scores[u] + scores[v] + scores[u_neighbor] +
                             scores[v_neighbor]);
        }
      };
      patty(edge[0], edge[1]);
      patty(edge[1], edge[0]);
    }
    return res;
  }
};

int main() { return 0; }