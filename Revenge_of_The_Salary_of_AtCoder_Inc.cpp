#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMax = 3e5 + 5, kMod = 998244353;
int n, a[kMax];

int fast_power(int base, int exp) {
  int res = 1;
  while (exp) {
    if (exp & 1) res = res * base % kMod;
    base = base * base % kMod;
    exp >>= 1;
  }
  return res;
}

int inv(int x) { return fast_power(x, kMod - 2); }

int get_at_round[kMax], not_get_at_round[kMax], pro[kMax];
void init() {
  get_at_round[1] = inv(n);
  not_get_at_round[1] = (n - 1) * inv(n) % kMod;
  for (int i = 2; i <= n; i++) {
    get_at_round[i] = not_get_at_round[i - 1] * inv(n) % kMod;
    not_get_at_round[i] = not_get_at_round[i - 1] * (n - 1) * inv(n) % kMod;
  }
  for (int i = 1; i <= n; i++) {
    pro[i] = pro[i - 1] + get_at_round[i];
    pro[i] %= kMod;
  }
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];

  init();
  int res = 0;

  for (int i = 1; i <= n; i++) {
    res += a[i] * pro[i] % kMod;
    res %= kMod;
  }
  cout << res << '\n';
  return 0;
}
