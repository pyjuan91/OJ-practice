#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, x, u, v;
  cin >> n >> m >> x;
  vector g(2, vector<vector<int>>(n + 1));
  while (m--) {
    cin >> u >> v;
    g[0][u].push_back(v);
    g[1][v].push_back(u);
  }
  vector dp(n + 1, vector(2, static_cast<int>(1e18)));
  dp[1][0] = 0;
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
  pq.push({ 0, 1, 0 });
  while (!pq.empty()) {
    auto [d, u, rev] = pq.top();
    pq.pop();
    // keep this state
    for (auto v : g[rev][u]) {
      if (dp[v][rev] > dp[u][rev] + 1) {
        dp[v][rev] = dp[u][rev] + 1;
        pq.push({ dp[v][rev], v, rev });
      }
    }
    // flip the edge
    if (dp[u][!rev] > dp[u][rev] + x) {
      dp[u][!rev] = dp[u][rev] + x;
      pq.push({ dp[u][!rev], u, !rev });
    }
  }
  cout << min(dp[n][0], dp[n][1]) << '\n';
  return 0;
}
