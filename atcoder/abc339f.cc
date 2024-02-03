#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  using i64 = uint64_t;
  using i128 = __uint128_t;

  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  const i64 kRandomMod =
      uniform_int_distribution<i64>(((i64)1 << 63), UINT64_MAX)(rng);
  i64 n;
  string s;
  cin >> n;
  vector<i64> a(n);
  unordered_map<i64, i64> cnt;

  auto transfer = [&](const string& s) -> i64 {
    i128 res = 0;
    for (char c : s) {
      res = res * 10 + c - '0';
      res %= kRandomMod;
    }
    return res;
  };

  for (i64 i = 0; i < n; i++) {
    cin >> s;
    a[i] = transfer(s);
    cnt[a[i]]++;
  }

  i64 res = 0;
  for (i64 i = 0; i < n; i++) {
    for (i64 j = 0; j < n; j++) {
      i128 x = (i128)a[i] * a[j] % kRandomMod;
      if (cnt.count(x)) res += cnt[x];
    }
  }

  cout << res << "\n";
  return 0;
}
