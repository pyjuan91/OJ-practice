#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

const int kMax = 1e7 + 5;
vector<int> lp(kMax + 1);
vector<int> pr;

void init() {
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
}

int haerin(int n) {
  int res = 0;
  auto it = prev(upper_bound(pr.begin(), pr.end(), n));
  // debug(*it, it - pr.begin());
  for (;;) {
    res += n / *it;
    if (it == pr.begin()) break;
    else it--;
  }
  return res;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  init();
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << haerin(n) << "\n";
  }
  return 0;
}
