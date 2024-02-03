#include <bits/stdc++.h>
using namespace std;
int main() {
  ifstream cin("meetings.in");
  ofstream cout("meetings.out");
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, sum = 0;
  cin >> n >> m;
  vector<int> w(n), x(n), d(n), id(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i] >> x[i] >> d[i];
    id[i] = i;
    sum += w[i];
  }
  sum = (sum + 1) / 2;
  sort(id.begin(), id.end(), [&](int i, int j) { return x[i] < x[j]; });
  vector<int> lx, rx;
  for (int i = 0; i < n; i++) {
    if (d[id[i]] == -1)
      lx.push_back(x[id[i]]);
    else
      rx.push_back(x[id[i]]);
  }
  vector<int> lw(lx.size()), rw(rx.size());
  for (int i = 0; i < lx.size(); i++) lw[i] = w[id[i]];
  for (int i = 0; i < rx.size(); i++) rw[i] = w[id[i + lx.size()]];

  vector<pair<int, int>> cows;
  for (int i = 0; i < lx.size(); i++) cows.push_back({lx[i], lw[i]});
  for (int i = 0; i < rx.size(); i++) cows.push_back({m - rx[i], rw[i]});
  sort(cows.begin(), cows.end());
  int target_time = 0;
  for (auto [time, weight] : cows) {
    if (sum <= weight) {
      target_time = time;
      break;
    }
    sum -= weight;
  }

  int res = 0;
  for (auto x : lx) {
    auto lb = lower_bound(rx.begin(), rx.end(), x);
    auto rb = lower_bound(rx.begin(), rx.end(), x - 2 * target_time);
    res += lb - rb;
  }
  cout << res << '\n';
  return 0;
}