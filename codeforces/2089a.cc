#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

const int kMax = 1e5 + 5;
vector<int> lp(kMax + 1);
vector<int> pr;

int init = []() {
  for (int i = 2; i <= kMax; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; i * pr[j] <= kMax; ++j) {
      lp[i * pr[j]] = pr[j];
      if (pr[j] == lp[i]) {
        break;
      }
    }
  }
  return 0;
}();

void patty(int n) {
  int L = n / 3;
  auto it = lower_bound(pr.begin(), pr.end(), L);

  vector<bool> used(n + 1, false);
  vector<int> res;
  res.reserve(n);

  res.push_back(*it);
  used[*it] = true;
  for (int d = 1;; d++) {
    if (res.size() < size_t(n) and *it - d >= 1)
      res.push_back(*it - d), used[*it - d] = true;
    else
      break;
    if (res.size() < size_t(n) and *it + d <= n)
      res.push_back(*it + d), used[*it + d] = true;
    else
      break;
  }

  for (int i = 1; i <= n; i++) {
    if (!used[i]) res.push_back(i);
  }

  for (auto x : res) cout << x << " ";
  cout << endl;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    patty(n);
  }
  return 0;
}
