#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  const int kMod = 1e9 + 7, kMax = 1e6 + 5;
  auto fast_power = [&](int base, int expo) {
    int result = 1;
    while (expo) {
      if (expo & 1) {
        result = (result * base) % kMod;
      }
      base = (base * base) % kMod;
      expo >>= 1;
    }
    return result;
  };
  auto mod_inverse = [&](int x) { return fast_power(x, kMod - 2); };

  vector<int> fact(kMax), inv_fact(kMax);
  fact[0] = 1;
  for (int i = 1; i < kMax; i++) {
    fact[i] = (fact[i - 1] * i) % kMod;
  }
  for (int i = 0; i < kMax; i++) {
    inv_fact[i] = mod_inverse(fact[i]);
  }

  int t, a, b;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    cout << (fact[a] * inv_fact[b] % kMod * inv_fact[a - b] % kMod) << '\n';
  }
  return 0;
}
