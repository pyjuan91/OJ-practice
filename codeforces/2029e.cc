#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

const int kMax = 4e5 + 5;
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
  // debug(lp);
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n);
    vector<int> primes, best_even;
    for (auto& x : a) {
      cin >> x;
      if (lp[x] == x) primes.push_back(x);
      else {
        if (x % 2 == 0) {
          best_even.push_back(x);
        }
        else {
          best_even.push_back(x - lp[x]);
        }
      }
    }

    if (primes.size() >= 2) {
      cout << "-1\n";
      continue;
    }

    if (primes.size() == 0) {
      cout << "2\n";
      continue;
    }

    bool ok = true;
    for (auto x : best_even) {
      if (x < primes[0] * 2) {
        ok = false;
        break;
      }
    }

    if (ok) {
      cout << primes[0] << "\n";
    }
    else {
      cout << "-1\n";
    }
  }
  return 0;
}
