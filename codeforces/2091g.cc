#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

const int kMax = 1e6 + 5;

int haerin(int s, int k) {
  if (s >= k * k) {
    if (s % k == 0) return k;
    return max(1LL, k - 2);
  }
  bitset<kMax> reachable, constrain;
  for (int i = 0; i <= s; i++) constrain.set(i);
  reachable.set(0);
  int dir = 1;
  for (;; k--) {
    bitset<kMax> new_reachable;
    if (k <= 0) k = 1;
    if (dir) new_reachable = reachable << k;
    else new_reachable = reachable >> k;
    for (int cnt = 1; cnt * k <= s; cnt++) {
      if (dir) new_reachable |= (new_reachable << k);
      else new_reachable |= (new_reachable >> k);
    }
    if (new_reachable[s]) {
      return k;
    }
    dir ^= 1;
    swap(reachable, new_reachable);
    reachable &= constrain;
  }
  return 0;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, s, k;
  cin >> t;
  while (t--) {
    cin >> s >> k;
    cout << haerin(s, k) << "\n";
  }
  return 0;
}
