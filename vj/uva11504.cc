#include <bits/stdc++.h>
using namespace std;

const int kMax = 1e5 + 5;
int t, n, m, u, v;
int dfn[kMax], low[kMax], in_stack[kMax], dfn_cnt, scc_cnt;
stack<int> stk;
int scc[kMax], scc_size[kMax];
vector<int> g[kMax];

void tarjan(int u) {
  low[u] = dfn[u] = ++dfn_cnt;
  stk.push(u), in_stack[u] = true;
  for (auto v : g[u]) {
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (in_stack[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (dfn[u] == low[u]) {
    scc_cnt++;
    while (true) {
      int x = stk.top();
      stk.pop(), in_stack[x] = false;
      scc[x] = scc_cnt, scc_size[scc_cnt]++;
      if (x == u) break;
    }
  }
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    while (m--) {
      cin >> u >> v;
      g[u].push_back(v);
    }
    // create a new DAG for those sccs
    for (int i = 1; i <= n; i++) {
      if (!dfn[i]) tarjan(i);
    }
    vector<set<int>> dag(scc_cnt + 1);
    for (int i = 1; i <= n; i++) {
      for (auto j : g[i]) {
        if (scc[i] != scc[j]) {
          dag[scc[i]].insert(scc[j]);
        }
      }
    }
    vector<int> in_degree(scc_cnt + 1);
    for (int i = 1; i <= scc_cnt; i++) {
      for (auto j : dag[i]) {
        in_degree[j]++;
      }
    }
    int res = 0;
    for (int i = 1; i <= scc_cnt; i++) {
      res += (in_degree[i] == 0);
    }
    cout << res << '\n';

    // reset
    for (int i = 1; i <= n; i++) {
      g[i].clear();
      dfn[i] = low[i] = in_stack[i] = 0;
    }
    for (int i = 1; i <= scc_cnt; i++) {
      scc[i] = scc_size[i] = 0;
    }
    dfn_cnt = scc_cnt = 0;
  }
  return 0;
}
