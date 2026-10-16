#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> left_cost(n + 1), right_cost(n + 1);
  for (int i = 2; i <= n; i++) cin >> left_cost[i];
  for (int i = 1; i < n; i++) cin >> right_cost[i];
  left_cost[1] == INT32_MAX;
  right_cost[n] == INT32_MAX;
  vector<int> suff_left = left_cost;
  vector<int> pref_right = right_cost;
  for (int i = n - 1; i >= 2; i--)
    suff_left[i] = min(left_cost[i], suff_left[i + 1]);
  for (int i = 2; i < n; i++)
    pref_right[i] = min(right_cost[i], pref_right[i - 1]);
  while (m--) {
    int src, dst;
    cin >> src >> dst;

    if (src < dst) {
      cout << min(right_cost[src], left_cost[src] + pref_right[src]) << "\n";
    } else {
      cout << min(left_cost[src], right_cost[src] + suff_left[src]) << "\n";
    }
  }
  return 0;
}
