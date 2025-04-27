#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
using namespace std;

constexpr int kMax = 3e5 + 5;
int n, k, d;
int police[kMax];
vector<pair<int, int>> adj[kMax];
bool vertex_visited[kMax], edge_visited[kMax];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n >> k >> d;
  for (int i = 1; i <= k; i++) {
    cin >> police[i];
  }

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v, i);
    adj[v].emplace_back(u, i);
  }

  queue<pair<int, int>> q;
  for (int i = 1; i <= k; i++) {
    q.push({ police[i], 0 });
    vertex_visited[police[i]] = true;
  }

  while (!q.empty()) {
    auto [u, dist] = q.front();
    q.pop();
    if (dist == d) continue;

    for (auto [v, edge_id] : adj[u]) {
      if (vertex_visited[v]) continue;
      edge_visited[edge_id] = true;
      vertex_visited[v] = true;
      q.push({ v, dist + 1 });
    }
  }

  int cnt = 0;
  for (int i = 1; i < n; i++) {
    if (not edge_visited[i]) {
      cnt++;
    }
  }
  cout << cnt << '\n';
  for (int i = 1; i < n; i++) {
    if (not edge_visited[i]) {
      cout << i << ' ';
    }
  }
  return 0;
}
