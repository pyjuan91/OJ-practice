#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMax = 2e5 + 5, kMod = 998244353;
int n, ten_pow[kMax] = {};

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  ten_pow[0] = 1;
  for (int i = 1; i < kMax; i++) {
    ten_pow[i] = ten_pow[i - 1] * 10 % kMod;
  }

  cin >> n;
  for (int i = 1; i < n; i++) {
    cout << (180 * ten_pow[n - i - 1] % kMod +
             81 * (n - 1 - i) * ten_pow[n - 1 - i] % kMod) %
                kMod
         << " ";
  }
  cout << "10\n";

  return 0;
}
