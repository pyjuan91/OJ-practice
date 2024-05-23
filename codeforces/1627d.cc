#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

const int kMax = 1e6 + 6;
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
bool check(vector<int>& candies) {
  for (int i = 0; i < candies.size(); i++) {
    for (int j = i + 1; j < candies.size(); j++) {
      if (__gcd(candies[i], candies[j]) == 1) {
        return true;
      }
    }
  }
  return false;
}
int n, a[kMax], cnt[kMax];
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  // init();
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int res = 0;
  for (int i = kMax / 3; i >= 1; i--) {
    if (cnt[i]) continue;
    int candies = 0;
    for (int j = 2 * i; j < kMax; j += i) {
      if (cnt[j]) {
        if (!candies) candies = j / i;
        else candies = gcd(candies, j / i);
      }
    }
    if ( candies == 1) {
      res++;
      cnt[i] = 1;
    }
    // if (i <= 20) debug(i, candies, check(candies));
  }
  cout << res << '\n';
  return 0;
}
