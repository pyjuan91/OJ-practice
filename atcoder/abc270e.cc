#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  for (int i = 0; i < n; i++)
    if (a[i] > 0) pq.push({a[i], i});
  int tot_sub = 0;
  while (true) {
    pair<int, int> p = pq.top();
    if ((p.first - tot_sub) * pq.size() < m) {
      m -= (p.first - tot_sub) * pq.size();
      tot_sub = p.first;
      pq.pop();
    } else {
      int all_sub = m / pq.size(), rem = m % pq.size();
      tot_sub += all_sub;
      for (int i = 0; i < n; i++) {
        a[i] -= tot_sub;
        a[i] = max(a[i], 0LL);
        if (a[i] == 0)
          cout << a[i] << ' ';
        else if (rem > 0)
          cout << a[i] - 1 << ' ', rem--;
        else
          cout << a[i] << ' ';
      }
      break;
    }
  }
  return 0;
}
