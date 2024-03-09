#include <bits/stdc++.h>
#define int long long
using namespace std;

int zuha(int n, int x, int y, vector<int>& p, vector<int>& c, int t) {
  int cur_time = t + x;
  for (int i = 0; i < n - 1; i++) {
    cur_time = (cur_time + p[i] - 1) / p[i] * p[i];
    cur_time += c[i];
  }
  cur_time += y;
  return cur_time - t;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, x, y, q, t;
  cin >> n >> x >> y;
  vector<int> p(n), c(n);
  for (int i = 0; i < n - 1; i++) cin >> p[i] >> c[i];
  vector<int> cost(840);
  for (int i = 0; i < 840; i++) {
    cost[i] = zuha(n, x, y, p, c, i);
  }
  cin >> q;
  while (q--) {
    cin >> t;
    cout << t + cost[t % 840] << '\n';
  }
  return 0;
}
