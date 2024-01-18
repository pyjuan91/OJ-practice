#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj, adj_rev;
vector<bool> visited;
vector<int> order, component;

void dfs1(int v) {
  visited[v] = true;
  for (int u : adj[v]) {
    if (!visited[u]) dfs1(u);
  }
  order.push_back(v);
}

void dfs2(int v) {
  visited[v] = true;
  component.push_back(v);
  for (int u : adj_rev[v]) {
    if (!visited[u]) dfs2(u);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  adj_rev.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj_rev[v].push_back(u);
  }

  visited.assign(n + 1, false);
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) dfs1(i);
  }

  vector<vector<int>> sccs;

  visited.assign(n + 1, false);
  for (int i = 0; i < n; i++) {
    int v = order[n - 1 - i];
    if (!visited[v]) {
      dfs2(v);
      sccs.push_back(component);
      component.clear();
    }
  }

  if (sccs.size() == 1) {
    cout << "YES\n";
  } else {
    visited.assign(n + 1, false);
    dfs1(sccs[0][0]);
    cout << "NO\n";
    if (visited[sccs[1][0]])
      cout << sccs[1][0] << " " << sccs[0][0] << "\n";
    else
      cout << sccs[0][0] << " " << sccs[1][0] << "\n";
  }

  return 0;
}