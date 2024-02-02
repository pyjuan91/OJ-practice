#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n, m, s, e, a, b, c;

  cin >> t;
  for (int kase = 1; kase <= t; kase++) {
    cin >> n >> m >> s >> e;
    using pii = pair<int, int>;
    vector<vector<pii>> g(n);
    while (m--) {
      cin >> a >> b >> c;
      g[a].emplace_back(make_pair(c, b));
      g[b].emplace_back(make_pair(c, a));
    }

    vector<int> dist(n, 1e9);
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, s));
    while (!pq.empty()) {
      auto [cost, node] = pq.top();
      pq.pop();
      for (auto [nxt_cost, next_node] : g[node]) {
        if (cost + nxt_cost < dist[next_node]) {
          dist[next_node] = cost + nxt_cost;
          pq.push(make_pair(dist[next_node], next_node));
        }
      }
    }

    cout << "Case #" << kase << ": ";
    if (dist[e] == 1e9)
      cout << "unreachable\n";
    else
      cout << dist[e] << "\n";
  }

  return 0;
}
