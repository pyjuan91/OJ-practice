#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMax = 1e7 + 5e6 + 5;
vector<int> lp(kMax, 0), primes;
void sieve() {
  for (int i = 2; i < kMax; i++) {
    if (lp[i] == 0) {
      lp[i] = i;
      primes.push_back(i);
    }
    for (int j = 0; i * primes[j] < kMax; j++) {
      lp[i * primes[j]] = primes[j];
      if (i % primes[j] == 0) break;
    }
  }
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  sieve();
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  int g = a[0];
  for (auto x : a) g = __gcd(g, x);
  vector<int> cnt(kMax, 0);
  for (auto x : a) {
    x /= g;
    while (x > 1) {
      int p = lp[x];
      while (x % p == 0) x /= p;
      cnt[p]++;
    }
  }
  int ma = 0;
  for (auto x : cnt) ma = max(ma, x);
  if (ma == 0) {
    cout << -1 << '\n';
  } else {
    cout << n - ma << '\n';
  }
  return 0;
}
