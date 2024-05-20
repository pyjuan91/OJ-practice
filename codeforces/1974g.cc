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

  int t, n, m, c;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    priority_queue<int> pq;
    int cur_profit = 0;
    for (int i = 0; i < n; i++) {
      cin >> c;
      pq.push(c);
      cur_profit -= c;
      while (cur_profit < 0) {
        cur_profit += pq.top();
        pq.pop();
      }
      // debug(pq, cur_profit);
      cur_profit += m;
    }
    cout << pq.size() << '\n';
  }
  return 0;
}
