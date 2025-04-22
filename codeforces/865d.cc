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
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& i : a) cin >> i;
  priority_queue<int, vector<int>, greater<int>> pq;
  int res = 0;
  for (auto& x : a) {
    pq.push(x);
    if (pq.top() < x) {
      res += x - pq.top();
      pq.pop();
      pq.push(x);
    }
  }
  cout << res << '\n';
  return 0;
}
