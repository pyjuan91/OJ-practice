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
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  vector<pair<int, int>> bad_intervals(m);
  for (auto& [l, r] : bad_intervals) {
    cin >> l >> r;
  }
  vector<pair<int, int>> good_intervals;
  int prev_right = 0;
  for (auto [l, r] : bad_intervals) {
    good_intervals.push_back({ prev_right + 1, l - 1 });
    prev_right = r;
  }
  good_intervals.push_back({ prev_right + 1, n });
  auto reachable = [&](int dist) -> bool {
    return (dist % a) <= dist / a * (b - a);
    };
  unordered_set<int> reachable_cells = { 1 };
  for (auto [l, r] : good_intervals) {
    for (int i = l; i <= min(r, l + b - 1); i++) {
      for (int step = a; step <= b; step++) {
        if (reachable_cells.count(i - step)) {
          reachable_cells.insert(i);
          break;
        }
      }
    }

    for (int i = max(l, r - b + 1); i <= r; i++) {
      for (int prv = l; prv <= min(r, l + b - 1); prv++) {
        int dist = i - prv;
        if (reachable_cells.count(prv) and reachable(dist)) {
          reachable_cells.insert(i);
          break;
        }
      }
    }
  }

  cout << (reachable_cells.count(n) ? "Yes" : "No") << '\n';
  return 0;
}
