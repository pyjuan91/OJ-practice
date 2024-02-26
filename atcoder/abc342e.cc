#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMax = 2e5 + 5;
int n, m, l, d, k, c, u, v;
struct Train {
  int l, d, k, c, from;
  Train(int l, int d, int k, int c, int from)
      : l(l), d(d), k(k), c(c), from(from) {}
  Train() {}
};
vector<Train> trains[kMax];
priority_queue<pair<int, int>> pq;
int latest[kMax] = {};

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n >> m;
  while (m--) {
    cin >> l >> d >> k >> c >> u >> v;
    trains[v].push_back(Train(l, d, k, c, u));
  }

  pq.push({INT64_MAX, n});
  while (!pq.empty()) {
    auto [time, node] = pq.top();
    pq.pop();
    if (latest[node] >= time) continue;
    latest[node] = time;
    for (auto train : trains[node]) {
      auto [l, d, k, c, from] = train;
      if (l <= time - c) {
        int lastest_time = min(l + (k - 1) * d, (time - c - l) / d * d + l);
        pq.push({lastest_time, from});
      }
    }
  }

  for (int i = 1; i < n; i++) {
    if (latest[i] == 0)
      cout << "Unreachable\n";
    else
      cout << latest[i] << "\n";
  }
  return 0;
}
