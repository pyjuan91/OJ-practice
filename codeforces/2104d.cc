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

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    sort(a.rbegin(), a.rend());

    int g = 0;
    for (int i = 0; i < n; i++) {
      g += a[i] - pr[i];
      if (g < 0) {
        cout << n - i << "\n";
        goto end;
      }
    }
    cout << 0 << "\n";
  end:;
  }
  return 0;
}
