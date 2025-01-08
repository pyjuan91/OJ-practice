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
  for (auto& x : pr) x = x * x;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  init();
  int n;
  cin >> n;
  int res = 0;
  for (int i = 0; i < pr.size(); i++) {
    int target_max = n / pr[i];
    if (target_max < pr[i + 1]) {
      break;
    }
    int index = upper_bound(pr.begin(), pr.end(), target_max) - pr.begin();
    res += index - i - 1;
  }
  for (int i = 0; i < pr.size(); i++) {
    int power_4 = pr[i] * pr[i];
    if (power_4 > n) {
      break;
    }
    int power_6 = power_4 * pr[i];
    if (power_6 > n) {
      break;
    }
    int power_8 = power_6 * pr[i];
    if (power_8 > n) {
      break;
    }
    res++;
  }
  cout << res << '\n';
  return 0;
}
