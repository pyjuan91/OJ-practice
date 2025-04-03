#include <bits/stdc++.h>
#include "atcoder/modint"
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;
using mint = atcoder::modint998244353;
using DPTable = array<array<array<array<mint, 2>, 2>, 2>, 40>;

mint fast_power(mint a, int b) {
  mint res = 1;
  while (b) {
    if (b & 1) res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}

mint chaewon(int a, int b) {
  DPTable dp{};
  dp[0][0][0][0] = 1;
  for (int i = 0; i <= 32; i++) {
    for (int f_a = 0; f_a < 2; f_a++) {
      for (int f_b = 0; f_b < 2; f_b++) {
        for (int f_x = 0; f_x < 2; f_x++) {
          mint cur_dp = dp[i][f_a][f_b][f_x];
          if (cur_dp == mint(0)) continue;
          int j = 32 - i;
          int cur_a = (a >> j) & 1;
          int cur_b = (b >> j) & 1;
          for (int bit_a = 0; bit_a < 2; bit_a++) {
            for (int bit_b = 0; bit_b < 2; bit_b++) {
              for (int bit_x = 0; bit_x < 2; bit_x++) {
                if (f_a == 0 and bit_a > cur_a) continue;
                if (f_b == 0 and bit_b > cur_b) continue;
                if (f_x == 0 and bit_x == 1 and (bit_a == 0 or bit_b == 0)) continue;
                int nf_a = f_a or (bit_a ^ cur_a);
                int nf_b = f_b or (bit_b ^ cur_b);
                int nf_x = f_x or bit_x;
                dp[i + 1][nf_a][nf_b][nf_x] += cur_dp;
              }
            }
          }
        }
      }
    }
  }

  mint res = 0;
  for (int f_a = 0; f_a < 2; f_a++) {
    for (int f_b = 0; f_b < 2; f_b++) {
      res += dp[33][f_a][f_b][1];
    }
  }
  return res;
}

mint haerin(int n, int m, int a, int b) {
  mint res = 0;
  mint choose_exactly_2_m = fast_power(mint(2), m) - 2;
  mint choose_exactly_2_n = fast_power(mint(2), n) - 2;
  mint mint_a = mint(a);
  mint mint_b = mint(b);
  debug(choose_exactly_2_m.val());
  debug(choose_exactly_2_n.val());
  res += (mint_a + 1) * (mint_b + 1);
  res += (mint_a + 1) * (mint_b * (mint_b + 1) / 2) * (choose_exactly_2_m);
  res += (mint_b + 1) * (mint_a * (mint_a + 1) / 2) * (choose_exactly_2_n);
  res += chaewon(a, b) * choose_exactly_2_n * choose_exactly_2_m;
  return res;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n, m, a, b;
  cin >> t;
  while (t--) {
    cin >> n >> m >> a >> b;
    cout << haerin(n, m, a, b).val() << "\n";
  }
  return 0;
}