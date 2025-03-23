#include <bits/stdc++.h>
#include "debug.cc"
using namespace std;

class Solution {
private:
  vector<int> getTargetNodes(vector<vector<int>>& g, int k) {
    int n = g.size();
    vector<int> res(n, 0);
    for (int i = 0; i < n; i++) {
      int cnt = 0;
      vector<bool> visited(n, false);
      queue<int> q, d;
      q.push(i);
      d.push(0);
      visited[i] = true;
      while (!q.empty()) {
        int u = q.front(), depth = d.front();
        q.pop();
        d.pop();
        cnt++;
        if (depth == k) {
          continue;
        }
        for (auto v : g[u]) {
          if (!visited[v]) {
            q.push(v);
            d.push(depth + 1);
            visited[v] = true;
          }
        }
      }
      res[i] = cnt;
    }
    return res;
  }
public:
  vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
    if (k == 0) {
      return vector<int>(edges1.size() + 1, 1);
    }
    int n = edges1.size() + 1, m = edges2.size() + 1;
    vector<vector<int>> g1(n), g2(m);
    for (int i = 0; i < n - 1; i++) {
      g1[edges1[i][0]].push_back(edges1[i][1]);
      g1[edges1[i][1]].push_back(edges1[i][0]);
    }
    for (int i = 0; i < m - 1; i++) {
      g2[edges2[i][0]].push_back(edges2[i][1]);
      g2[edges2[i][1]].push_back(edges2[i][0]);
    }
    vector<int> res1 = std::move(getTargetNodes(g1, k));
    vector<int> res2 = std::move(getTargetNodes(g2, k - 1));
    int res2_max = *max_element(res2.begin(), res2.end());
    for (auto& x : res1) {
      x += res2_max;
    }
    return res1;
  }
};

int main() {
  Solution s;
  vector<vector<int>> edges1 = { {0, 1}, {0, 2}, {2, 3}, {2, 4} };
  vector<vector<int>> edges2 = { {0, 1}, {0, 2}, {0, 3}, {2, 7}, {1, 4}, {4, 5} ,{4, 6} };
  int k = 2;
  vector<int> res = s.maxTargetNodes(edges1, edges2, k);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}