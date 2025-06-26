#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

int patty(int n, vector<int>& a) {
  priority_queue<int> pq;
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      pq.push(a[i]);
    } else {
      pq.push(a[2 * i - 1]), pq.push(a[2 * i]);
    }
    res += pq.top();
    pq.pop();
  }
  return res;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(2 * n);
    for (auto& x : a) cin >> x;
    cout << patty(n, a) << '\n';
  }
  return 0;
}
