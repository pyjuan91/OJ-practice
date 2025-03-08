#include <bits/stdc++.h>
#include "debug.cc"

using namespace std;

struct Edge {
  int from, to, weight;
  Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}
  Edge() {}
  bool operator<(const Edge& other) const {
    if (weight == other.weight) {
      if (from == other.from) {
        return to < other.to;
      }
      return from < other.from;
    }
    return weight < other.weight;
  }
};

void print(Edge edge) {
  cerr << edge.from << " " << edge.to << " " << edge.weight << "\n";
}

class Solution {
public:
  int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
    vector adj(n, vector<pair<int, int>>());
    for (auto& edge : edges) {
      adj[edge[1]].push_back({ edge[0], edge[2] });
    }
    set<Edge> pq;
    vector<bool> visited(n, false);
    int maxWeight = INT32_MIN;
    visited[0] = true;
    for (auto& [to, weight] : adj[0]) {
      pq.insert(Edge(0, to, weight));
    }
    while (!pq.empty()) {
      auto edge = *pq.begin();
      pq.erase(pq.begin());
      if (visited[edge.to]) {
        continue;
      }
      visited[edge.to] = true;
      maxWeight = max(maxWeight, edge.weight);
      for (auto& [to, weight] : adj[edge.to]) {
        if (!visited[to]) {
          pq.insert(Edge(edge.to, to, weight));
        }
      }
    }
    return count(visited.begin(), visited.end(), true) == n ? maxWeight : -1;
  }
};

int main() {
  int n, threshold;
  cin >> n >> threshold;
  vector<vector<int>> edges;
  int u, v, w;
  while (cin >> u >> v >> w) {
    edges.push_back({ u, v, w });
  }
  Solution s;
  cout << s.minMaxWeight(n, edges, threshold) << endl;
  return 0;
}